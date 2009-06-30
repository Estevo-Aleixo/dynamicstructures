#ifndef PROBLEMPRESETDIALOG_H
#define PROBLEMPRESETDIALOG_H

#include <QtGui/QDialog>

namespace Ui {
    class ProblemPresetDialog;
}

class ProblemPresetDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(ProblemPresetDialog)
public:
    explicit ProblemPresetDialog(QWidget *parent = 0);
    virtual ~ProblemPresetDialog();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::ProblemPresetDialog *m_ui;
};

#endif // PROBLEMPRESETDIALOG_H
