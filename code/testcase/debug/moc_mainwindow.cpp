/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue Jun 30 13:42:03 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      48,   11,   11,   11, 0x08,
      82,   11,   11,   11, 0x08,
     109,   11,   11,   11, 0x08,
     140,   11,   11,   11, 0x08,
     164,   11,   11,   11, 0x08,
     198,   11,   11,   11, 0x08,
     231,   11,   11,   11, 0x08,
     262,   11,   11,   11, 0x08,
     276,  273,   11,   11, 0x08,
     295,   11,   11,   11, 0x08,
     306,   11,   11,   11, 0x08,
     319,   11,   11,   11, 0x08,
     332,   11,   11,   11, 0x08,
     356,   11,   11,   11, 0x08,
     370,   11,   11,   11, 0x08,
     384,   11,   11,   11, 0x08,
     397,   11,   11,   11, 0x08,
     410,   11,   11,   11, 0x08,
     435,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_btnExecuteSpanningStep_clicked()\0"
    "on_btnLocateFightPoints_clicked()\0"
    "on_btnLoadPreset_clicked()\0"
    "on_bntResultFileName_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_btnExecutePathFinder_clicked()\0"
    "on_btnForestFullScreen_clicked()\0"
    "on_btnGenerateForest_clicked()\0"
    "addNodes()\0on\0nodeDrawMode(bool)\0"
    "addEdges()\0deleteTool()\0selectTool()\0"
    "clearProblemStructure()\0openProblem()\0"
    "saveProblem()\0newProblem()\0saveResult()\0"
    "createProblemStructure()\0showLogWindow()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btnExecuteSpanningStep_clicked(); break;
        case 1: on_btnLocateFightPoints_clicked(); break;
        case 2: on_btnLoadPreset_clicked(); break;
        case 3: on_bntResultFileName_clicked(); break;
        case 4: on_pushButton_clicked(); break;
        case 5: on_btnExecutePathFinder_clicked(); break;
        case 6: on_btnForestFullScreen_clicked(); break;
        case 7: on_btnGenerateForest_clicked(); break;
        case 8: addNodes(); break;
        case 9: nodeDrawMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: addEdges(); break;
        case 11: deleteTool(); break;
        case 12: selectTool(); break;
        case 13: clearProblemStructure(); break;
        case 14: openProblem(); break;
        case 15: saveProblem(); break;
        case 16: newProblem(); break;
        case 17: saveResult(); break;
        case 18: createProblemStructure(); break;
        case 19: showLogWindow(); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
