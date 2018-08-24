/****************************************************************************
** Meta object code from reading C++ file 'htmllogger.h'
**
** Created: Fri Aug 24 12:21:23 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "htmllogger.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'htmllogger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HTMLLogger[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   37,   11,   11, 0x0a,
      89,   74,   11,   11, 0x0a,
     130,  117,   11,   11, 0x0a,
     167,  156,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HTMLLogger[] = {
    "HTMLLogger\0\0html\0logUpdated(QString)\0"
    "sender,info\0addInfo(QString,QString)\0"
    "sender,warning\0addWarning(QString,QString)\0"
    "sender,error\0addError(QString,QString)\0"
    "color,text\0addLine(QString,QString)\0"
};

void HTMLLogger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HTMLLogger *_t = static_cast<HTMLLogger *>(_o);
        switch (_id) {
        case 0: _t->logUpdated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->addInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->addWarning((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->addError((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->addLine((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HTMLLogger::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HTMLLogger::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HTMLLogger,
      qt_meta_data_HTMLLogger, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HTMLLogger::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HTMLLogger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HTMLLogger::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HTMLLogger))
        return static_cast<void*>(const_cast< HTMLLogger*>(this));
    return QObject::qt_metacast(_clname);
}

int HTMLLogger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void HTMLLogger::logUpdated(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
