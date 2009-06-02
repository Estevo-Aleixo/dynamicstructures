/********************************************************************************
** Form generated from reading ui file 'initscene.ui'
**
** Created: Tue Jun 2 14:51:47 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_INITSCENE_H
#define UI_INITSCENE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_InitScene
{
public:

    void setupUi(QDialog *InitScene)
    {
        if (InitScene->objectName().isEmpty())
            InitScene->setObjectName(QString::fromUtf8("InitScene"));
        InitScene->resize(400, 300);

        retranslateUi(InitScene);

        QMetaObject::connectSlotsByName(InitScene);
    } // setupUi

    void retranslateUi(QDialog *InitScene)
    {
        InitScene->setWindowTitle(QApplication::translate("InitScene", "Dialog", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(InitScene);
    } // retranslateUi

};

namespace Ui {
    class InitScene: public Ui_InitScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITSCENE_H
