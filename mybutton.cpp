#include "mybutton.h"

MyButton::MyButton(QWidget *parent):QPushButton(parent)
{


}

void MyButton::setupContents(int id, const QString & title, const QString & info) {
    this->id = id;
    this->name = title;
    this->info = info;
}
