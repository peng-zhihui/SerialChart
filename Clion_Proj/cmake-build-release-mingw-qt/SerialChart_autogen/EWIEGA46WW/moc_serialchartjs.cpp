/****************************************************************************
** Meta object code from reading C++ file 'serialchartjs.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../serialchartjs.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialchartjs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WebViewObject_t {
    QByteArrayData data[9];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebViewObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebViewObject_t qt_meta_stringdata_WebViewObject = {
    {
QT_MOC_LITERAL(0, 0, 13), // "WebViewObject"
QT_MOC_LITERAL(1, 14, 4), // "eval"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "scriptSource"
QT_MOC_LITERAL(4, 33, 7), // "hexPack"
QT_MOC_LITERAL(5, 41, 1), // "v"
QT_MOC_LITERAL(6, 43, 4), // "type"
QT_MOC_LITERAL(7, 48, 9), // "hexUnpack"
QT_MOC_LITERAL(8, 58, 9) // "hexString"

    },
    "WebViewObject\0eval\0\0scriptSource\0"
    "hexPack\0v\0type\0hexUnpack\0hexString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebViewObject[] = {

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

 // methods: name, argc, parameters, tag, flags
       4,    2,   32,    2, 0x02 /* Public */,
       7,    2,   37,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::QVariant, QMetaType::QString,    3,

 // methods: parameters
    QMetaType::QString, QMetaType::QVariant, QMetaType::QString,    5,    6,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QString,    8,    6,

       0        // eod
};

void WebViewObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WebViewObject *_t = static_cast<WebViewObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QVariant _r = _t->eval((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 1: { QString _r = _t->hexPack((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 2: { QVariant _r = _t->hexUnpack((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef QVariant (WebViewObject::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebViewObject::eval)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject WebViewObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WebViewObject.data,
      qt_meta_data_WebViewObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WebViewObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebViewObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WebViewObject.stringdata0))
        return static_cast<void*>(const_cast< WebViewObject*>(this));
    return QObject::qt_metacast(_clname);
}

int WebViewObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QVariant WebViewObject::eval(const QString & _t1)
{
    QVariant _t0 = QVariant();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
