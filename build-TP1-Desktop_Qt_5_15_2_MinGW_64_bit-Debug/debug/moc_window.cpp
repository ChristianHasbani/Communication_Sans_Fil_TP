/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../TP1/window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Window_t {
    QByteArrayData data[15];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_t qt_meta_stringdata_Window = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Window"
QT_MOC_LITERAL(1, 7, 24), // "on_connectButton_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 12), // "close_reader"
QT_MOC_LITERAL(4, 46, 22), // "on_readCardBtn_clicked"
QT_MOC_LITERAL(5, 69, 8), // "initCard"
QT_MOC_LITERAL(6, 78, 18), // "on_quitBtn_clicked"
QT_MOC_LITERAL(7, 97, 27), // "on_disconnectButton_clicked"
QT_MOC_LITERAL(8, 125, 23), // "on_updateButton_clicked"
QT_MOC_LITERAL(9, 149, 17), // "on_payBtn_clicked"
QT_MOC_LITERAL(10, 167, 22), // "updateSuccessLEDBuzzer"
QT_MOC_LITERAL(11, 190, 7), // "int16_t"
QT_MOC_LITERAL(12, 198, 6), // "status"
QT_MOC_LITERAL(13, 205, 21), // "updateFailedLEDBuzzer"
QT_MOC_LITERAL(14, 227, 20) // "on_chargeBtn_clicked"

    },
    "Window\0on_connectButton_clicked\0\0"
    "close_reader\0on_readCardBtn_clicked\0"
    "initCard\0on_quitBtn_clicked\0"
    "on_disconnectButton_clicked\0"
    "on_updateButton_clicked\0on_payBtn_clicked\0"
    "updateSuccessLEDBuzzer\0int16_t\0status\0"
    "updateFailedLEDBuzzer\0on_chargeBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,
      13,    1,   80,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,

       0        // eod
};

void Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_connectButton_clicked(); break;
        case 1: _t->close_reader(); break;
        case 2: _t->on_readCardBtn_clicked(); break;
        case 3: _t->initCard(); break;
        case 4: _t->on_quitBtn_clicked(); break;
        case 5: _t->on_disconnectButton_clicked(); break;
        case 6: _t->on_updateButton_clicked(); break;
        case 7: _t->on_payBtn_clicked(); break;
        case 8: _t->updateSuccessLEDBuzzer((*reinterpret_cast< int16_t(*)>(_a[1]))); break;
        case 9: _t->updateFailedLEDBuzzer((*reinterpret_cast< int16_t(*)>(_a[1]))); break;
        case 10: _t->on_chargeBtn_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Window::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Window.data,
    qt_meta_data_Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Window.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
