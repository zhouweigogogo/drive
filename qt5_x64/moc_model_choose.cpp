/****************************************************************************
** Meta object code from reading C++ file 'model_choose.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "model_choose.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'model_choose.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_model_choose_t {
    QByteArrayData data[9];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_model_choose_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_model_choose_t qt_meta_stringdata_model_choose = {
    {
QT_MOC_LITERAL(0, 0, 12), // "model_choose"
QT_MOC_LITERAL(1, 13, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(4, 62, 23), // "on_search_model_clicked"
QT_MOC_LITERAL(5, 86, 21), // "on_model_test_clicked"
QT_MOC_LITERAL(6, 108, 38), // "on_model_choose_box_currentTe..."
QT_MOC_LITERAL(7, 147, 12), // "currentcoose"
QT_MOC_LITERAL(8, 160, 11) // "updateImage"

    },
    "model_choose\0on_pushButton_4_clicked\0"
    "\0on_pushButton_3_clicked\0"
    "on_search_model_clicked\0on_model_test_clicked\0"
    "on_model_choose_box_currentTextChanged\0"
    "currentcoose\0updateImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_model_choose[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void model_choose::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        model_choose *_t = static_cast<model_choose *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_4_clicked(); break;
        case 1: _t->on_pushButton_3_clicked(); break;
        case 2: _t->on_search_model_clicked(); break;
        case 3: _t->on_model_test_clicked(); break;
        case 4: _t->on_model_choose_box_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->updateImage(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject model_choose::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_model_choose.data,
    qt_meta_data_model_choose,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *model_choose::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *model_choose::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_model_choose.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int model_choose::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
