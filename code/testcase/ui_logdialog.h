/********************************************************************************
** Form generated from reading ui file 'logdialog.ui'
**
** Created: Tue Jun 30 12:04:18 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LOGDIALOG_H
#define UI_LOGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogDialog
{
public:
    QLabel *label_2;
    QWidget *textParentWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *LogDialog)
    {
        if (LogDialog->objectName().isEmpty())
            LogDialog->setObjectName(QString::fromUtf8("LogDialog"));
        LogDialog->resize(666, 488);
        label_2 = new QLabel(LogDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 81, 16));
        textParentWidget = new QWidget(LogDialog);
        textParentWidget->setObjectName(QString::fromUtf8("textParentWidget"));
        textParentWidget->setGeometry(QRect(10, 50, 641, 421));
        pushButton = new QPushButton(LogDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 20, 111, 23));

        retranslateUi(LogDialog);

        QMetaObject::connectSlotsByName(LogDialog);
    } // setupUi

    void retranslateUi(QDialog *LogDialog)
    {
        LogDialog->setWindowTitle(QApplication::translate("LogDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LogDialog", "Debug output:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("LogDialog", "Clear Debug output", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(LogDialog);
    } // retranslateUi

};

namespace Ui {
    class LogDialog: public Ui_LogDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGDIALOG_H
