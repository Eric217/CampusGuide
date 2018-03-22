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

    initButtons();
    initGraph();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initGraph() {
    graph = AdjacencyWGraph<int>(22);
    graph.addEdge(1, 12, 80);


}


void MainWindow::initButtons() {
    ui->pushButton_ALibrary1->setupContents(1, QString("Library"), QString("This is the only library"));
    ui->pushButton_Bathroom2->setupContents(2, QString("Bathroom"), QString("This is the only Bathroom"));
    ui->pushButton_Block13->setupContents(3, QString("Block1"), QString("Block1"));
    ui->pushButton_Block24->setupContents(4, QString("Block2"), QString("Block2"));
    ui->pushButton_Block35->setupContents(5, QString("Block3"), QString("Block3"));
    ui->pushButton_Block46->setupContents(6, QString("Block4"), QString("Block4"));
    ui->pushButton_Block57->setupContents(7, QString("Block5"), QString("Block5"));
    ui->pushButton_DiningHall8->setupContents(8, QString("DiningHall"), QString("Main DiningHall"));
    ui->pushButton_Door19->setupContents(9, QString("Door1"), QString(" Door1"));
    ui->pushButton_Door210->setupContents(10, QString("Door2"), QString(" Door2"));
    ui->pushButton_Dorm111->setupContents(11, QString("Dorm1"), QString(" Dorm1"));
    ui->pushButton_Dorm212->setupContents(12, QString("Dorm2"), QString(" Dorm2"));
    ui->pushButton_Dorm313->setupContents(13, QString("Dorm3"), QString(" Dorm3"));
    ui->pushButton_Dorm414->setupContents(14, QString("Dorm4"), QString(" Dorm4"));
    ui->pushButton_Dorm515->setupContents(15, QString("Dorm5"), QString(" Dorm5"));
    ui->pushButton_Dorm616->setupContents(16, QString("Dorm6"), QString(" Dorm6"));
    ui->pushButton_Experiment17->setupContents(17, QString("Experiment"), QString(" Experiment Building"));
    ui->pushButton_Gym18->setupContents(18, QString("Gym"), QString("This is the only Gym"));
    ui->pushButton_Office19->setupContents(19, QString("Office"), QString("This is the only Office"));
    ui->pushButton_RKeyan20->setupContents(20, QString("ScienceOfExp"), QString("This is the only ScienceOfExp"));
    ui->pushButton_SJiaoyan21->setupContents(21, QString("ScienceOfTeach"), QString("This is the only ScienceOfTeach"));
    ui->pushButton_TJiaoxue22->setupContents(22, QString("Teaching"), QString("This is the only Teaching"));
}

///////////////////////////////////////////
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
///////////////////////////////////////////
