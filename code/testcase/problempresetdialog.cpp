#include "problempresetdialog.h"
#include "ui_problempresetdialog.h"

ProblemPresetDialog::ProblemPresetDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::ProblemPresetDialog)
{
    m_ui->setupUi(this);
}

ProblemPresetDialog::~ProblemPresetDialog()
{
    delete m_ui;
}

void ProblemPresetDialog::changeEvent(QEvent *e)
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
