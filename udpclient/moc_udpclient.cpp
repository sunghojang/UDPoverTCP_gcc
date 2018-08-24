/****************************************************************************
** Meta object code from reading C++ file 'udpclient.h'
**
** Created: Fri Aug 24 12:21:37 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "udpclient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UDPClient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   11,   10,   10, 0x05,
      53,   41,   10,   10, 0x05,
      90,   75,   10,   10, 0x05,
     128,  115,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     151,   11,   10,   10, 0x0a,
     172,   10,   10,   10, 0x08,
     195,  183,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UDPClient[] = {
    "UDPClient\0\0data\0dataReceived(QByteArray)\0"
    "sender,info\0info(QString,QString)\0"
    "sender,warning\0warning(QString,QString)\0"
    "sender,error\0error(QString,QString)\0"
    "sendData(QByteArray)\0readData()\0"
    "socketError\0displayError(QAbstractSocket::SocketError)\0"
};

void UDPClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UDPClient *_t = static_cast<UDPClient *>(_o);
        switch (_id) {
        case 0: _t->dataReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->info((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->warning((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->error((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->sendData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 5: _t->readData(); break;
        case 6: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UDPClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UDPClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UDPClient,
      qt_meta_data_UDPClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UDPClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UDPClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UDPClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UDPClient))
        return static_cast<void*>(const_cast< UDPClient*>(this));
    return QObject::qt_metacast(_clname);
}

int UDPClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void UDPClient::dataReceived(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UDPClient::info(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UDPClient::warning(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void UDPClient::error(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
