#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setFixedSize(1028,597);
    ui->setupUi(this);
    ui->frameLogin->hide();
    ui->frameSearch_2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonLibrary_clicked()
{
    ui->textEdit->hide();
}

void MainWindow::on_pushButton_25_clicked()
{
    ui->frameLogin->hide();
}

void MainWindow::on_pushButton_24_clicked()
{
    ui->frameLogin->show();
}

void MainWindow::on_pushButton_Clear_clicked()
{
    ui->textEditSearch->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->frameSearch_2->hide();
}
