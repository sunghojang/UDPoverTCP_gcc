/****************************************************************************
** Meta object code from reading C++ file 'snbtests.h'
**
** Created: Fri Aug 24 12:22:01 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "snbtests.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'snbtests.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SNBTests[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   10,    9,    9, 0x08,
      38,   33,    9,    9, 0x08,
      68,   63,    9,    9, 0x08,
     107,    9,    9,    9, 0x08,
     131,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SNBTests[] = {
    "SNBTests\0\0log\0updateLog(QString)\0data\0"
    "receivedData(QByteArray)\0arg1\0"
    "on_spinBoxListenPort_valueChanged(int)\0"
    "on_buttonSend_clicked()\0"
    "on_buttonClearLogger_clicked()\0"
};

void SNBTests::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SNBTests *_t = static_cast<SNBTests *>(_o);
        switch (_id) {
        case 0: _t->updateLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->receivedData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->on_spinBoxListenPort_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_buttonSend_clicked(); break;
        case 4: _t->on_buttonClearLogger_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SNBTests::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SNBTests::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SNBTests,
      qt_meta_data_SNBTests, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SNBTests::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SNBTests::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SNBTests::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SNBTests))
        return static_cast<void*>(const_cast< SNBTests*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SNBTests::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
