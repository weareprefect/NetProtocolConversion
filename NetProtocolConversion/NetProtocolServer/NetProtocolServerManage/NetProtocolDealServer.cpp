#include "NetProtocolDealServer.h"
#include <QtCore/QDebug>
#include <QtCore/QCoreApplication>
//#include <TlHelp32.h>
//构造函数
NetProtolSocket::NetProtolSocket(qintptr handle, QObject *parent)
	: QTcpSocket(parent), handle_(handle)
{
	this->setSocketDescriptor(handle_);
	//断开连接消息
	connect(this, &NetProtolSocket::disconnected, [&]()
	{
		this->deleteLater();
		emit this->ClientDisconnected(handle_);
	});

	connect(this,
		SIGNAL(readyRead()),
		this,
		SLOT(receiveProjectMessage()));
}
//主动断开连接槽
void  NetProtolSocket::DisconnectSocket(qintptr handle)
{
	if (handle == handle_)
		disconnectFromHost();
}


void  NetProtolSocket::receiveProjectMessage()
{
	QByteArray receiveBuff = this->readAll();
	QString strBuff = receiveBuff;
	//qDebug() << strBuff;
	QStringList paramList = strBuff.split(",");
	QByteArray buff = strBuff.toUtf8();
	this->write(buff);
}

//构造函数
NetProtolSocketGenServcie::NetProtolSocketGenServcie(QObject *parent)
	: QTcpServer(parent),
	private_(new NetProtolServerPrivate)
{

}
//析构函数
NetProtolSocketGenServcie::~NetProtolSocketGenServcie()
{
	for (NetProtolSocket *client : private_->clients.values())
	{
		client->disconnectFromHost();
		auto handle = client->socketDescriptor();
		client->deleteLater();
		//告知其他调用者 当前socket断开，避免有需要在socket后执行的方法
		emit ClientDisconnected(handle);
	}
	if (private_)
		delete private_;
	this->close();
}
//重写-有连接到来
void NetProtolSocketGenServcie::incomingConnection(qintptr handle)
{
	//超出最大级数量关闭连接
	if (private_->clients.size() > maxPendingConnections())
	{
		QTcpSocket tcp;
		tcp.setSocketDescriptor(handle);
		tcp.disconnectFromHost();
		return;
	}
	auto client_socket = new NetProtolSocket(handle);
	Q_ASSERT(client_socket->socketDescriptor() == handle);
	//socket断开连接的信号与server槽连接
	connect(client_socket,
		&NetProtolSocket::ClientDisconnected,
		this,
		&NetProtolSocketGenServcie::ClientDisconnectedSlot);
	//主动断开连接的操作
	connect(this,
		&NetProtolSocketGenServcie::InitiativeDisConnectClient,
		client_socket,
		&NetProtolSocket::DisconnectSocket);

	//map记录
	private_->clients.insert(handle, client_socket);
	qDebug() << handle << "connected";
	emit ClientConnected(handle, client_socket);
}

//客户端已断开槽
void NetProtolSocketGenServcie::ClientDisconnectedSlot(qintptr handle)
{
	//map中移除
	private_->clients.remove(handle);
	qDebug() << handle << "disconnected";
	//发出信号
	emit ClientDisconnected(handle);
}

