/****************************************************************************
** Meta object code from reading C++ file 'ocrneural.h'
**
** Created: Tue Jan 28 22:45:27 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ocrneural.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ocrneural.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OCRNeural[] = {

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
      42,   10,   10,   10, 0x08,
      74,   10,   10,   10, 0x08,
     107,   10,   10,   10, 0x08,
     144,  136,   10,   10, 0x08,
     181,  136,   10,   10, 0x08,
     217,  212,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OCRNeural[] = {
    "OCRNeural\0\0on_action_Training_triggered()\0"
    "on_actionLoad_Image_triggered()\0"
    "on_actionLoad_Neural_triggered()\0"
    "on_actionRun_OCR_triggered()\0checked\0"
    "on_showThresholdAction_clicked(bool)\0"
    "on_ShowBoxAction_clicked(bool)\0arg1\0"
    "on_thresholdVal_valueChanged(int)\0"
};

const QMetaObject OCRNeural::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_OCRNeural,
      qt_meta_data_OCRNeural, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OCRNeural::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OCRNeural::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OCRNeural::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OCRNeural))
        return static_cast<void*>(const_cast< OCRNeural*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int OCRNeural::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_action_Training_triggered(); break;
        case 1: on_actionLoad_Image_triggered(); break;
        case 2: on_actionLoad_Neural_triggered(); break;
        case 3: on_actionRun_OCR_triggered(); break;
        case 4: on_showThresholdAction_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: on_ShowBoxAction_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: on_thresholdVal_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
