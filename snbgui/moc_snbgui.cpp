/****************************************************************************
** Meta object code from reading C++ file 'snbgui.h'
**
** Created: Fri Aug 24 12:21:49 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "snbgui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'snbgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SNBGui[] = {

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
      12,    8,    7,    7, 0x08,
      37,   31,    7,    7, 0x08,
      64,    7,    7,    7, 0x08,
      95,    7,    7,    7, 0x08,
     126,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SNBGui[] = {
    "SNBGui\0\0log\0updateLog(QString)\0count\0"
    "updateConnectionCount(int)\0"
    "on_buttonUTStartStop_clicked()\0"
    "on_buttonTUStartStop_clicked()\0"
    "on_buttonClearLogger_clicked()\0"
};

void SNBGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SNBGui *_t = static_cast<SNBGui *>(_o);
        switch (_id) {
        case 0: _t->updateLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->updateConnectionCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_buttonUTStartStop_clicked(); break;
        case 3: _t->on_buttonTUStartStop_clicked(); break;
        case 4: _t->on_buttonClearLogger_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SNBGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SNBGui::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SNBGui,
      qt_meta_data_SNBGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SNBGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SNBGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SNBGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SNBGui))
        return static_cast<void*>(const_cast< SNBGui*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SNBGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
