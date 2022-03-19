// NetProtocolServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <QCoreApplication>
#include "NetProtocolServerManage/NetProtocolDealServer.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	NetProtolSocketGenServcie genHttpService;
	NetProtolSocketGenServcie genMQTTService;
	NetProtolSocketGenServcie genAQMPService;
	NetProtolSocketGenServcie genCOAPService;
	bool bRet = genHttpService.listen(QHostAddress::Any, 543210);
	bRet = genMQTTService.listen(QHostAddress::Any, 543212);
	bRet = genAQMPService.listen(QHostAddress::Any, 543214);
	bRet = genCOAPService.listen(QHostAddress::Any, 543216);

	return a.exec();
}


