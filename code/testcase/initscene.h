#ifndef INITSCENE_H
#define INITSCENE_H

#include <QtGui/QDialog>

namespace Ui {
    class InitScene;
}

class InitScene : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(InitScene)
public:
    explicit InitScene(QWidget *parent = 0);
    virtual ~InitScene();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::InitScene *m_ui;
};

#endif // INITSCENE_H
