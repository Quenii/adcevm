/****************************************************************************
** Meta object code from reading C++ file 'RegAccessItem.h'
**
** Created: Sat Sep 4 20:42:17 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RegAccessItem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RegAccessItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RegAccessItem[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

       0        // eod
};

static const char qt_meta_stringdata_RegAccessItem[] = {
    "RegAccessItem\0"
};

const QMetaObject RegAccessItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RegAccessItem,
      qt_meta_data_RegAccessItem, 0 }
};

const QMetaObject *RegAccessItem::metaObject() const
{
    return &staticMetaObject;
}

void *RegAccessItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RegAccessItem))
        return static_cast<void*>(const_cast< RegAccessItem*>(this));
    if (!strcmp(_clname, "Ui::RegAccessItemClass"))
        return static_cast< Ui::RegAccessItemClass*>(const_cast< RegAccessItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int RegAccessItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE