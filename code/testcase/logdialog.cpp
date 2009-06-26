#include "logdialog.h"
#include "ui_logdialog.h"

LogDialog::LogDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::LogDialog)
{
    m_ui->setupUi(this);

   mLog= new LogWindow(m_ui->textParentWidget);
   mLog->resize(m_ui->textParentWidget->width(), m_ui->textParentWidget->height());
   mLog->setReadOnly(true);
   mLog->show();
}

LogDialog::~LogDialog()
{
    delete m_ui;
}

void LogDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void LogDialog::on_pushButton_clicked()
{
     mLog->clear();
}
