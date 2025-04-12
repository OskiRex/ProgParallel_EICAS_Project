/****************************************************************************
** Meta object code from reading C++ file 'EICAS_DataReader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "EICAS_DataReader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EICAS_DataReader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EICAS_DataReader_t {
    QByteArrayData data[9];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EICAS_DataReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EICAS_DataReader_t qt_meta_stringdata_EICAS_DataReader = {
    {
QT_MOC_LITERAL(0, 0, 16), // "EICAS_DataReader"
QT_MOC_LITERAL(1, 17, 14), // "alertaActivada"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "mensaje"
QT_MOC_LITERAL(4, 41, 4), // "tipo"
QT_MOC_LITERAL(5, 46, 5), // "color"
QT_MOC_LITERAL(6, 52, 13), // "tiempoVirtual"
QT_MOC_LITERAL(7, 66, 17), // "alertaDesactivada"
QT_MOC_LITERAL(8, 84, 9) // "leerLinea"

    },
    "EICAS_DataReader\0alertaActivada\0\0"
    "mensaje\0tipo\0color\0tiempoVirtual\0"
    "alertaDesactivada\0leerLinea"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EICAS_DataReader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   29,    2, 0x06 /* Public */,
       7,    1,   38,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void EICAS_DataReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EICAS_DataReader *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->alertaActivada((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->alertaDesactivada((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->leerLinea(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EICAS_DataReader::*)(const QString & , const QString & , const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EICAS_DataReader::alertaActivada)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EICAS_DataReader::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EICAS_DataReader::alertaDesactivada)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EICAS_DataReader::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EICAS_DataReader.data,
    qt_meta_data_EICAS_DataReader,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EICAS_DataReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EICAS_DataReader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EICAS_DataReader.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EICAS_DataReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void EICAS_DataReader::alertaActivada(const QString & _t1, const QString & _t2, const QString & _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EICAS_DataReader::alertaDesactivada(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
