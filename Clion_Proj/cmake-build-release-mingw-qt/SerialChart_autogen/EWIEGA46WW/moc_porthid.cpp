/****************************************************************************
** Meta object code from reading C++ file 'porthid.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../porthid.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'porthid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PortHid_t {
    QByteArrayData data[8];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PortHid_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PortHid_t qt_meta_stringdata_PortHid = {
    {
QT_MOC_LITERAL(0, 0, 7), // "PortHid"
QT_MOC_LITERAL(1, 8, 7), // "newData"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 7), // "stopped"
QT_MOC_LITERAL(4, 25, 7), // "message"
QT_MOC_LITERAL(5, 33, 4), // "text"
QT_MOC_LITERAL(6, 38, 4), // "type"
QT_MOC_LITERAL(7, 43, 13) // "requestToStop"

    },
    "PortHid\0newData\0\0stopped\0message\0text\0"
    "type\0requestToStop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PortHid[] = {

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
       1,    1,   34,    2, 0x06 /* Public */,
       3,    0,   37,    2, 0x06 /* Public */,
       4,    2,   38,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void PortHid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PortHid *_t = static_cast<PortHid *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->stopped(); break;
        case 2: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->requestToStop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PortHid::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PortHid::newData)) {
                *result = 0;
            }
        }
        {
            typedef void (PortHid::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PortHid::stopped)) {
                *result = 1;
            }
        }
        {
            typedef void (PortHid::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PortHid::message)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject PortHid::staticMetaObject = {
    { &PortBase::staticMetaObject, qt_meta_stringdata_PortHid.data,
      qt_meta_data_PortHid,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PortHid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PortHid::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PortHid.stringdata0))
        return static_cast<void*>(const_cast< PortHid*>(this));
    return PortBase::qt_metacast(_clname);
}

int PortHid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PortBase::qt_metacall(_c, _id, _a);
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
void PortHid::newData(const QByteArray & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PortHid::stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void PortHid::message(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
