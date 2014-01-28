/****************************************************************************
** Meta object code from reading C++ file 'ftraining.h'
**
** Created: Tue Jan 28 22:45:32 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ftraining.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftraining.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FTraining[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      42,   37,   10,   10, 0x08,
      84,   76,   10,   10, 0x08,
     121,   76,   10,   10, 0x08,
     152,   10,   10,   10, 0x08,
     186,   10,   10,   10, 0x08,
     212,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FTraining[] = {
    "FTraining\0\0on_actionOpen_triggered()\0"
    "arg1\0on_thresholdVal_valueChanged(int)\0"
    "checked\0on_showThresholdAction_clicked(bool)\0"
    "on_ShowBoxAction_clicked(bool)\0"
    "on_actionRun_Learning_triggered()\0"
    "on_actionSave_triggered()\0"
    "on_actionLoad_Weight_Neuron_triggered()\0"
};

const QMetaObject FTraining::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FTraining,
      qt_meta_data_FTraining, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FTraining::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FTraining::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FTraining::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FTraining))
        return static_cast<void*>(const_cast< FTraining*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FTraining::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionOpen_triggered(); break;
        case 1: on_thresholdVal_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: on_showThresholdAction_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: on_ShowBoxAction_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: on_actionRun_Learning_triggered(); break;
        case 5: on_actionSave_triggered(); break;
        case 6: on_actionLoad_Weight_Neuron_triggered(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
