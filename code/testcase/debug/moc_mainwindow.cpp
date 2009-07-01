/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Jul 1 17:06:28 2009
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
      23,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      40,   11,   11,   11, 0x08,
      84,   11,   11,   11, 0x08,
     127,   11,   11,   11, 0x08,
     163,   11,   11,   11, 0x08,
     197,   11,   11,   11, 0x08,
     224,   11,   11,   11, 0x08,
     255,   11,   11,   11, 0x08,
     279,   11,   11,   11, 0x08,
     313,   11,   11,   11, 0x08,
     346,   11,   11,   11, 0x08,
     377,   11,   11,   11, 0x08,
     391,  388,   11,   11, 0x08,
     410,   11,   11,   11, 0x08,
     421,   11,   11,   11, 0x08,
     434,   11,   11,   11, 0x08,
     447,   11,   11,   11, 0x08,
     471,   11,   11,   11, 0x08,
     485,   11,   11,   11, 0x08,
     499,   11,   11,   11, 0x08,
     512,   11,   11,   11, 0x08,
     525,   11,   11,   11, 0x08,
     550,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_btnResetCanvas_clicked()\0"
    "on_chkMinimumSpanningTreeSolution_clicked()\0"
    "on_chkMinimumSpanningTreeProblem_clicked()\0"
    "on_btnExecuteSpanningStep_clicked()\0"
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
        case 0: on_btnResetCanvas_clicked(); break;
        case 1: on_chkMinimumSpanningTreeSolution_clicked(); break;
        case 2: on_chkMinimumSpanningTreeProblem_clicked(); break;
        case 3: on_btnExecuteSpanningStep_clicked(); break;
        case 4: on_btnLocateFightPoints_clicked(); break;
        case 5: on_btnLoadPreset_clicked(); break;
        case 6: on_bntResultFileName_clicked(); break;
        case 7: on_pushButton_clicked(); break;
        case 8: on_btnExecutePathFinder_clicked(); break;
        case 9: on_btnForestFullScreen_clicked(); break;
        case 10: on_btnGenerateForest_clicked(); break;
        case 11: addNodes(); break;
        case 12: nodeDrawMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: addEdges(); break;
        case 14: deleteTool(); break;
        case 15: selectTool(); break;
        case 16: clearProblemStructure(); break;
        case 17: openProblem(); break;
        case 18: saveProblem(); break;
        case 19: newProblem(); break;
        case 20: saveResult(); break;
        case 21: createProblemStructure(); break;
        case 22: showLogWindow(); break;
        default: ;
        }
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
