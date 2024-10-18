/****************************************************************************
** Meta object code from reading C++ file 'TRecADCChParamWidgets.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../TRecADCChParamWidgets.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TRecADCChParamWidgets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_CTRecADCChParamWidgets_t {
    uint offsetsAndSizes[18];
    char stringdata0[23];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[18];
    char stringdata5[19];
    char stringdata6[17];
    char stringdata7[3];
    char stringdata8[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CTRecADCChParamWidgets_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CTRecADCChParamWidgets_t qt_meta_stringdata_CTRecADCChParamWidgets = {
    {
        QT_MOC_LITERAL(0, 22),  // "CTRecADCChParamWidgets"
        QT_MOC_LITERAL(23, 15),  // "on_ChApplyCheck"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 5),  // "value"
        QT_MOC_LITERAL(46, 17),  // "on_ChTriggerCheck"
        QT_MOC_LITERAL(64, 18),  // "on_ChTriggerSlider"
        QT_MOC_LITERAL(83, 16),  // "on_ChTriggerMode"
        QT_MOC_LITERAL(100, 2),  // "Id"
        QT_MOC_LITERAL(103, 20)   // "on_ChTriggerPolarity"
    },
    "CTRecADCChParamWidgets",
    "on_ChApplyCheck",
    "",
    "value",
    "on_ChTriggerCheck",
    "on_ChTriggerSlider",
    "on_ChTriggerMode",
    "Id",
    "on_ChTriggerPolarity"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CTRecADCChParamWidgets[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x08,    1 /* Private */,
       4,    1,   47,    2, 0x08,    3 /* Private */,
       5,    1,   50,    2, 0x08,    5 /* Private */,
       6,    1,   53,    2, 0x08,    7 /* Private */,
       8,    1,   56,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject CTRecADCChParamWidgets::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CTRecADCChParamWidgets.offsetsAndSizes,
    qt_meta_data_CTRecADCChParamWidgets,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CTRecADCChParamWidgets_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CTRecADCChParamWidgets, std::true_type>,
        // method 'on_ChApplyCheck'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_ChTriggerCheck'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_ChTriggerSlider'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_ChTriggerMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_ChTriggerPolarity'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void CTRecADCChParamWidgets::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CTRecADCChParamWidgets *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_ChApplyCheck((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_ChTriggerCheck((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_ChTriggerSlider((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_ChTriggerMode((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_ChTriggerPolarity((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *CTRecADCChParamWidgets::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CTRecADCChParamWidgets::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CTRecADCChParamWidgets.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CTRecADCChParamWidgets::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
