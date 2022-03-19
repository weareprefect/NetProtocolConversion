#pragma once
#include <QMap>
#include <QtCore/QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

class NetProtolSocket : public QTcpSocket
{
	Q_OBJECT
public:
	NetProtolSocket(qintptr handle, QObject *parent = 0);
signals:
	/*
	* 已断开连接信号
	*/
	void ClientDisconnected(qintptr);
	public slots:
	/**
	* @brief 断开连接
	* @param handle 连接句柄
	*/
	void DisconnectSocket(qintptr handle);

	private slots:
	void receiveProjectMessage();

private:
	qintptr handle_;
};
/**
* @brief Tcp多客户端服务器私有类
*/
class NetProtolServerPrivate
{
public:
	QMap<int, NetProtolSocket *> clients; ///所有连接的map
};


/**
* @brief Tcp多客户端服务器
*/
class NetProtolSocketGenServcie : public QTcpServer
{
	Q_OBJECT
public:
	/**
	* @brief 构造函数
	* @param parent 父QObject
	*/
	explicit NetProtolSocketGenServcie(QObject *parent = Q_NULLPTR);
	/**
	* @brief 析构函数
	*    非多线程模式行为：关闭所有连接后析构
	*    多线程模式行为：关闭所有连接及线程池后析构
	*/
	~NetProtolSocketGenServcie();

	NetProtolServerPrivate* getServerPrivte()
	{
		return private_;
	}
signals:
	/**
	* @brief 客户端连入
	* @param 连接句柄
	* @param socket指针
	*/
	void ClientConnected(qintptr, QTcpSocket*);//发送新用户连接信息
											   /**
											   * @brief socket已断开连接
											   *   若需要在socket后析构后进行操作的可连接此信号
											   * @param 连接句柄
											   */
	void ClientDisconnected(qintptr);
	/**
	* @brief 主动断开连接信号
	*   若服务端想要主动断开与客户端连接将会发出此信号
	*   此信号发出这表明进行断开操作不表明断开成功，成功以SocketDisconnected信号为准
	* @param 连接句柄
	*/
	void InitiativeDisConnectClient(qintptr);
	protected slots:
	/**
	* @brief 客户端已断开槽
	*   此槽与客户端的已断开信号连接
	* @param handle
	*/
	void ClientDisconnectedSlot(qintptr handle);
protected:
	/**
	* @brief 重写-有连接到来
	*    连接到来不一定连接，会根据maxPendingConnections决定是否连接
	* @param handle 连接句柄
	*/
	virtual void incomingConnection(qintptr handle);


private:
	NetProtolServerPrivate *private_;
};
