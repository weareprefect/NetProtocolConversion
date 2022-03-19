#include "NetProtocolDealServer.h"
#include <QtCore/QDebug>
#include <QtCore/QCoreApplication>
//#include <TlHelp32.h>
//���캯��
NetProtolSocket::NetProtolSocket(qintptr handle, QObject *parent)
	: QTcpSocket(parent), handle_(handle)
{
	this->setSocketDescriptor(handle_);
	//�Ͽ�������Ϣ
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
//�����Ͽ����Ӳ�
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

//���캯��
NetProtolSocketGenServcie::NetProtolSocketGenServcie(QObject *parent)
	: QTcpServer(parent),
	private_(new NetProtolServerPrivate)
{

}
//��������
NetProtolSocketGenServcie::~NetProtolSocketGenServcie()
{
	for (NetProtolSocket *client : private_->clients.values())
	{
		client->disconnectFromHost();
		auto handle = client->socketDescriptor();
		client->deleteLater();
		//��֪���������� ��ǰsocket�Ͽ�����������Ҫ��socket��ִ�еķ���
		emit ClientDisconnected(handle);
	}
	if (private_)
		delete private_;
	this->close();
}
//��д-�����ӵ���
void NetProtolSocketGenServcie::incomingConnection(qintptr handle)
{
	//������������ر�����
	if (private_->clients.size() > maxPendingConnections())
	{
		QTcpSocket tcp;
		tcp.setSocketDescriptor(handle);
		tcp.disconnectFromHost();
		return;
	}
	auto client_socket = new NetProtolSocket(handle);
	Q_ASSERT(client_socket->socketDescriptor() == handle);
	//socket�Ͽ����ӵ��ź���server������
	connect(client_socket,
		&NetProtolSocket::ClientDisconnected,
		this,
		&NetProtolSocketGenServcie::ClientDisconnectedSlot);
	//�����Ͽ����ӵĲ���
	connect(this,
		&NetProtolSocketGenServcie::InitiativeDisConnectClient,
		client_socket,
		&NetProtolSocket::DisconnectSocket);

	//map��¼
	private_->clients.insert(handle, client_socket);
	qDebug() << handle << "connected";
	emit ClientConnected(handle, client_socket);
}

//�ͻ����ѶϿ���
void NetProtolSocketGenServcie::ClientDisconnectedSlot(qintptr handle)
{
	//map���Ƴ�
	private_->clients.remove(handle);
	qDebug() << handle << "disconnected";
	//�����ź�
	emit ClientDisconnected(handle);
}

