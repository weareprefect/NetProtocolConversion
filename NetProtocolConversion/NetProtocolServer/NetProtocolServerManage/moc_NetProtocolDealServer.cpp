/****************************************************************************
** Meta object code from reading C++ file 'NetProtocolDealServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "NetProtocolDealServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NetProtocolDealServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NetProtolSocket_t {
    QByteArrayData data[7];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetProtolSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetProtolSocket_t qt_meta_stringdata_NetProtolSocket = {
    {
QT_MOC_LITERAL(0, 0, 15), // "NetProtolSocket"
QT_MOC_LITERAL(1, 16, 18), // "ClientDisconnected"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7), // "qintptr"
QT_MOC_LITERAL(4, 44, 16), // "DisconnectSocket"
QT_MOC_LITERAL(5, 61, 6), // "handle"
QT_MOC_LITERAL(6, 68, 21) // "receiveProjectMessage"

    },
    "NetProtolSocket\0ClientDisconnected\0\0"
    "qintptr\0DisconnectSocket\0handle\0"
    "receiveProjectMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetProtolSocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x0a /* Public */,
       6,    0,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    5,
    QMetaType::Void,

       0        // eod
};

void NetProtolSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetProtolSocket *_t = static_cast<NetProtolSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ClientDisconnected((*reinterpret_cast< qintptr(*)>(_a[1]))); break;
        case 1: _t->DisconnectSocket((*reinterpret_cast< qintptr(*)>(_a[1]))); break;
        case 2: _t->receiveProjectMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NetProtolSocket::*_t)(qintptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetProtolSocket::ClientDisconnected)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject NetProtolSocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_NetProtolSocket.data,
      qt_meta_data_NetProtolSocket,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NetProtolSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetProtolSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NetProtolSocket.stringdata0))
        return static_cast<void*>(const_cast< NetProtolSocket*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int NetProtolSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void NetProtolSocket::ClientDisconnected(qintptr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_NetProtolSocketGenServcie_t {
    QByteArrayData data[9];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetProtolSocketGenServcie_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetProtolSocketGenServcie_t qt_meta_stringdata_NetProtolSocketGenServcie = {
    {
QT_MOC_LITERAL(0, 0, 25), // "NetProtolSocketGenServcie"
QT_MOC_LITERAL(1, 26, 15), // "ClientConnected"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 7), // "qintptr"
QT_MOC_LITERAL(4, 51, 11), // "QTcpSocket*"
QT_MOC_LITERAL(5, 63, 18), // "ClientDisconnected"
QT_MOC_LITERAL(6, 82, 26), // "InitiativeDisConnectClient"
QT_MOC_LITERAL(7, 109, 22), // "ClientDisconnectedSlot"
QT_MOC_LITERAL(8, 132, 6) // "handle"

    },
    "NetProtolSocketGenServcie\0ClientConnected\0"
    "\0qintptr\0QTcpSocket*\0ClientDisconnected\0"
    "InitiativeDisConnectClient\0"
    "ClientDisconnectedSlot\0handle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetProtolSocketGenServcie[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    1,   39,    2, 0x06 /* Public */,
       6,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   45,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    8,

       0        // eod
};

void NetProtolSocketGenServcie::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetProtolSocketGenServcie *_t = static_cast<NetProtolSocketGenServcie *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ClientConnected((*reinterpret_cast< qintptr(*)>(_a[1])),(*reinterpret_cast< QTcpSocket*(*)>(_a[2]))); break;
        case 1: _t->ClientDisconnected((*reinterpret_cast< qintptr(*)>(_a[1]))); break;
        case 2: _t->InitiativeDisConnectClient((*reinterpret_cast< qintptr(*)>(_a[1]))); break;
        case 3: _t->ClientDisconnectedSlot((*reinterpret_cast< qintptr(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NetProtolSocketGenServcie::*_t)(qintptr , QTcpSocket * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetProtolSocketGenServcie::ClientConnected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NetProtolSocketGenServcie::*_t)(qintptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetProtolSocketGenServcie::ClientDisconnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NetProtolSocketGenServcie::*_t)(qintptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetProtolSocketGenServcie::InitiativeDisConnectClient)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject NetProtolSocketGenServcie::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_NetProtolSocketGenServcie.data,
      qt_meta_data_NetProtolSocketGenServcie,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NetProtolSocketGenServcie::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetProtolSocketGenServcie::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NetProtolSocketGenServcie.stringdata0))
        return static_cast<void*>(const_cast< NetProtolSocketGenServcie*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int NetProtolSocketGenServcie::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void NetProtolSocketGenServcie::ClientConnected(qintptr _t1, QTcpSocket * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetProtolSocketGenServcie::ClientDisconnected(qintptr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NetProtolSocketGenServcie::InitiativeDisConnectClient(qintptr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
