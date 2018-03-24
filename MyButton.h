#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <qpushbutton.h>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    int id;
    QString name;
    QString info;

    MyButton(QWidget *parent);
    void setupContents(int id, const QString & name, const QString & info);

};

#endif // MYBUTTON_H

