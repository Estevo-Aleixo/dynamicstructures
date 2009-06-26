#ifndef LOGDIALOG_H
#define LOGDIALOG_H

#include <QtGui/QDialog>
#include "LogWindow.h"

namespace Ui {
    class LogDialog;
}

class LogDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(LogDialog)
public:
    explicit LogDialog(QWidget *parent = 0);
    virtual ~LogDialog();


    //todo rename
    LogWindow* getLogWindow(){return mLog;}
    void  setLogWindow(LogWindow* log){mLog=log;}


protected:
    LogWindow* mLog;

    virtual void changeEvent(QEvent *e);

private:
    Ui::LogDialog *m_ui;

private slots:
    void on_pushButton_clicked();
};

#endif // LOGDIALOG_H
