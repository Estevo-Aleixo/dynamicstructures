#ifndef LOGWINDOW_H
#define LOGWINDOW_H
#include "BaseHeaders.h"
#include <QTextEdit>



enum MsgType{succes_msg,failure_msg,important_msg,very_important_msg, normal_msg, sub_msg};

class LogWindow : public QTextEdit
{
public:
    LogWindow(QWidget * parent = 0);

    void log(std::string&  msg, MsgType type=normal_msg);

    void log(QString  msg,MsgType type=normal_msg);
    void log(char* msg,MsgType type=normal_msg);
    inline void logToBuffer(QString  msg, MsgType type=normal_msg)
    {
        QString br= "<br/>";
        mBufferedStr+= "<div style='"+ getStyle(type) +"' >" + getTime()+  " - " + msg + "</div>";
    }
    void flush();

    //void clear(){QTextEdit::clear();}
private:
    QString getTime();
    QString getStyle(MsgType type);
    QString mBufferedStr;

};


#endif // LOGWINDOW_H
