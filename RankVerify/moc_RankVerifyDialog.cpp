/****************************************************************************
** Meta object code from reading C++ file 'RankVerifyDialog.h'
**
** Created: Fri Apr 2 02:44:48 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "RankVerifyDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RankVerifyDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RankVerifyDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RankVerifyDialog[] = {
    "RankVerifyDialog\0\0valueChanged()\0"
    "setValue()\0"
};

const QMetaObject RankVerifyDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RankVerifyDialog,
      qt_meta_data_RankVerifyDialog, 0 }
};

const QMetaObject *RankVerifyDialog::metaObject() const
{
    return &staticMetaObject;
}

void *RankVerifyDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RankVerifyDialog))
        return static_cast<void*>(const_cast< RankVerifyDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int RankVerifyDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChanged(); break;
        case 1: setValue(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void RankVerifyDialog::valueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
