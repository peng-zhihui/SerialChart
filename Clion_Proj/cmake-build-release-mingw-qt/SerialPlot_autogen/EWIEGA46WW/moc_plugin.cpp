/****************************************************************************
** Meta object code from reading C++ file 'plugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../plugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Plugin_t {
    QByteArrayData data[23];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Plugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Plugin_t qt_meta_stringdata_Plugin = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Plugin"
QT_MOC_LITERAL(1, 7, 4), // "eval"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 12), // "scriptSource"
QT_MOC_LITERAL(4, 26, 13), // "slotNewPacket"
QT_MOC_LITERAL(5, 40, 12), // "DecoderBase*"
QT_MOC_LITERAL(6, 53, 7), // "decoder"
QT_MOC_LITERAL(7, 61, 13), // "slotPortReady"
QT_MOC_LITERAL(8, 75, 6), // "portID"
QT_MOC_LITERAL(9, 82, 7), // "hexPack"
QT_MOC_LITERAL(10, 90, 1), // "v"
QT_MOC_LITERAL(11, 92, 4), // "type"
QT_MOC_LITERAL(12, 97, 9), // "hexUnpack"
QT_MOC_LITERAL(13, 107, 9), // "hexString"
QT_MOC_LITERAL(14, 117, 9), // "hexEscape"
QT_MOC_LITERAL(15, 127, 6), // "string"
QT_MOC_LITERAL(16, 134, 11), // "hexUnescape"
QT_MOC_LITERAL(17, 146, 9), // "newPacket"
QT_MOC_LITERAL(18, 156, 6), // "values"
QT_MOC_LITERAL(19, 163, 13), // "setDataFormat"
QT_MOC_LITERAL(20, 177, 10), // "dataFormat"
QT_MOC_LITERAL(21, 188, 13), // "getDataFormat"
QT_MOC_LITERAL(22, 202, 8) // "portSend"

    },
    "Plugin\0eval\0\0scriptSource\0slotNewPacket\0"
    "DecoderBase*\0decoder\0slotPortReady\0"
    "portID\0hexPack\0v\0type\0hexUnpack\0"
    "hexString\0hexEscape\0string\0hexUnescape\0"
    "newPacket\0values\0setDataFormat\0"
    "dataFormat\0getDataFormat\0portSend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Plugin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   72,    2, 0x0a /* Public */,
       7,    1,   75,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       9,    2,   78,    2, 0x02 /* Public */,
      12,    2,   83,    2, 0x02 /* Public */,
      14,    1,   88,    2, 0x02 /* Public */,
      16,    1,   91,    2, 0x02 /* Public */,
      17,    1,   94,    2, 0x02 /* Public */,
      19,    1,   97,    2, 0x02 /* Public */,
      21,    0,  100,    2, 0x02 /* Public */,
      22,    2,  101,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::QVariant, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    8,

 // methods: parameters
    QMetaType::QString, QMetaType::QVariant, QMetaType::QString,   10,   11,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QString,   13,   11,
    QMetaType::QString, QMetaType::QString,   15,
    QMetaType::QString, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Bool, QMetaType::QString,   20,
    QMetaType::QString,
    QMetaType::QVariant, QMetaType::Int, QMetaType::QString,    8,   15,

       0        // eod
};

void Plugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Plugin *_t = static_cast<Plugin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QVariant _r = _t->eval((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 1: _t->slotNewPacket((*reinterpret_cast< DecoderBase*(*)>(_a[1]))); break;
        case 2: _t->slotPortReady((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { QString _r = _t->hexPack((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: { QVariant _r = _t->hexUnpack((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 5: { QString _r = _t->hexEscape((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { QString _r = _t->hexUnescape((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: _t->newPacket((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: { bool _r = _t->setDataFormat((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { QString _r = _t->getDataFormat();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 10: { QVariant _r = _t->portSend((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DecoderBase* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef QVariant (Plugin::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Plugin::eval)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Plugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Plugin.data,
      qt_meta_data_Plugin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Plugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Plugin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Plugin.stringdata0))
        return static_cast<void*>(const_cast< Plugin*>(this));
    return QObject::qt_metacast(_clname);
}

int Plugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
QVariant Plugin::eval(const QString & _t1)
{
    QVariant _t0 = QVariant();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
