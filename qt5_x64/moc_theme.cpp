/****************************************************************************
** Meta object code from reading C++ file 'theme.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "theme.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'theme.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_theme_t {
    QByteArrayData data[11];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_theme_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_theme_t qt_meta_stringdata_theme = {
    {
QT_MOC_LITERAL(0, 0, 5), // "theme"
QT_MOC_LITERAL(1, 6, 12), // "update_theme"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "imgpath"
QT_MOC_LITERAL(4, 28, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 50, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(6, 74, 24), // "on_radioButton_5_clicked"
QT_MOC_LITERAL(7, 99, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(8, 122, 24), // "on_radioButton_2_clicked"
QT_MOC_LITERAL(9, 147, 24), // "on_radioButton_3_clicked"
QT_MOC_LITERAL(10, 172, 24) // "on_radioButton_4_clicked"

    },
    "theme\0update_theme\0\0imgpath\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_radioButton_5_clicked\0"
    "on_radioButton_clicked\0on_radioButton_2_clicked\0"
    "on_radioButton_3_clicked\0"
    "on_radioButton_4_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_theme[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   59,    2, 0x08 /* Private */,
       5,    0,   60,    2, 0x08 /* Private */,
       6,    0,   61,    2, 0x08 /* Private */,
       7,    0,   62,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    0,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void theme::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        theme *_t = static_cast<theme *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_theme((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_radioButton_5_clicked(); break;
        case 4: _t->on_radioButton_clicked(); break;
        case 5: _t->on_radioButton_2_clicked(); break;
        case 6: _t->on_radioButton_3_clicked(); break;
        case 7: _t->on_radioButton_4_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (theme::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&theme::update_theme)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject theme::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_theme.data,
    qt_meta_data_theme,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *theme::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *theme::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_theme.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int theme::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void theme::update_theme(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
