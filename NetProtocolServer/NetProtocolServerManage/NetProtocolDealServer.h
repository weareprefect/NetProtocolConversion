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
	* �ѶϿ������ź�
	*/
	void ClientDisconnected(qintptr);
	public slots:
	/**
	* @brief �Ͽ�����
	* @param handle ���Ӿ��
	*/
	void DisconnectSocket(qintptr handle);

	private slots:
	void receiveProjectMessage();

private:
	qintptr handle_;
};
/**
* @brief Tcp��ͻ��˷�����˽����
*/
class NetProtolServerPrivate
{
public:
	QMap<int, NetProtolSocket *> clients; ///�������ӵ�map
};


/**
* @brief Tcp��ͻ��˷�����
*/
class NetProtolSocketGenServcie : public QTcpServer
{
	Q_OBJECT
public:
	/**
	* @brief ���캯��
	* @param parent ��QObject
	*/
	explicit NetProtolSocketGenServcie(QObject *parent = Q_NULLPTR);
	/**
	* @brief ��������
	*    �Ƕ��߳�ģʽ��Ϊ���ر��������Ӻ�����
	*    ���߳�ģʽ��Ϊ���ر��������Ӽ��̳߳غ�����
	*/
	~NetProtolSocketGenServcie();

	NetProtolServerPrivate* getServerPrivte()
	{
		return private_;
	}
signals:
	/**
	* @brief �ͻ�������
	* @param ���Ӿ��
	* @param socketָ��
	*/
	void ClientConnected(qintptr, QTcpSocket*);//�������û�������Ϣ
											   /**
											   * @brief socket�ѶϿ�����
											   *   ����Ҫ��socket����������в����Ŀ����Ӵ��ź�
											   * @param ���Ӿ��
											   */
	void ClientDisconnected(qintptr);
	/**
	* @brief �����Ͽ������ź�
	*   ���������Ҫ�����Ͽ���ͻ������ӽ��ᷢ�����ź�
	*   ���źŷ�����������жϿ������������Ͽ��ɹ����ɹ���SocketDisconnected�ź�Ϊ׼
	* @param ���Ӿ��
	*/
	void InitiativeDisConnectClient(qintptr);
	protected slots:
	/**
	* @brief �ͻ����ѶϿ���
	*   �˲���ͻ��˵��ѶϿ��ź�����
	* @param handle
	*/
	void ClientDisconnectedSlot(qintptr handle);
protected:
	/**
	* @brief ��д-�����ӵ���
	*    ���ӵ�����һ�����ӣ������maxPendingConnections�����Ƿ�����
	* @param handle ���Ӿ��
	*/
	virtual void incomingConnection(qintptr handle);


private:
	NetProtolServerPrivate *private_;
};
