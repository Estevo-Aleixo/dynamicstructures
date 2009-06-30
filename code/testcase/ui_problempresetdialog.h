/********************************************************************************
** Form generated from reading ui file 'problempresetdialog.ui'
**
** Created: Tue Jun 30 12:04:18 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PROBLEMPRESETDIALOG_H
#define UI_PROBLEMPRESETDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ProblemPresetDialog
{
public:
    QListView *listView;
    QTableView *tableView;
    QPushButton *pushButton_2;
    QLabel *label_33;
    QLabel *label_32;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QDialog *ProblemPresetDialog)
    {
        if (ProblemPresetDialog->objectName().isEmpty())
            ProblemPresetDialog->setObjectName(QString::fromUtf8("ProblemPresetDialog"));
        ProblemPresetDialog->resize(410, 244);
        listView = new QListView(ProblemPresetDialog);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(20, 30, 201, 161));
        tableView = new QTableView(ProblemPresetDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(240, 30, 141, 161));
        pushButton_2 = new QPushButton(ProblemPresetDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 210, 81, 21));
        label_33 = new QLabel(ProblemPresetDialog);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(240, 10, 71, 16));
        label_32 = new QLabel(ProblemPresetDialog);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(20, 10, 46, 14));
        label = new QLabel(ProblemPresetDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 200, 61, 16));
        textEdit = new QTextEdit(ProblemPresetDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(80, 200, 231, 31));
        textEdit->setFrameShape(QFrame::NoFrame);
        textEdit->setReadOnly(true);

        retranslateUi(ProblemPresetDialog);

        QMetaObject::connectSlotsByName(ProblemPresetDialog);
    } // setupUi

    void retranslateUi(QDialog *ProblemPresetDialog)
    {
        ProblemPresetDialog->setWindowTitle(QApplication::translate("ProblemPresetDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ProblemPresetDialog", "Load", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("ProblemPresetDialog", "Properties:", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("ProblemPresetDialog", "Presets:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ProblemPresetDialog", "description:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ProblemPresetDialog);
    } // retranslateUi

};

namespace Ui {
    class ProblemPresetDialog: public Ui_ProblemPresetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROBLEMPRESETDIALOG_H
