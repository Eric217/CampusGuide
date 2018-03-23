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
    delete [] buttons;
    delete ui;
}

void MainWindow::initGraph() {
    graph = AdjacencyWGraph<int>(SITES);
    graph.addEdge(1, 12, 80);
    graph.addEdge(1, 21, 30);
    graph.addEdge(1, 20, 40);
    graph.addEdge(1, 3, 40);
    graph.addEdge(1, 22, 50);

    graph.addEdge(22, 21, 60);
    graph.addEdge(21, 17, 10);
    graph.addEdge(12, 21, 90);
    graph.addEdge(20, 21, 50);
    graph.addEdge(21, 3, 50);

    graph.addEdge(17, 10, 10);
    graph.addEdge(10, 20, 10);
    graph.addEdge(9, 10, 15);

    graph.addEdge(20, 22, 15);
    graph.addEdge(20, 3, 10);
    graph.addEdge(20, 12, 65);

    graph.addEdge(22, 9, 25);
    graph.addEdge(22, 19, 20);
    graph.addEdge(22, 7, 15);
    graph.addEdge(22, 3, 15);
    graph.addEdge(22, 12, 80);

    graph.addEdge(8, 9, 55);
    graph.addEdge(7, 9, 25);
    graph.addEdge(19, 9, 30);
    graph.addEdge(8, 19, 20);
    graph.addEdge(8, 13, 30);

    graph.addEdge(7, 19, 15);
    graph.addEdge(11, 19, 15);
    graph.addEdge(7, 6, 5);
    graph.addEdge(6, 5, 5);
    graph.addEdge(4, 5, 5);
    graph.addEdge(4, 3, 5);
    graph.addEdge(3, 12, 65);

    graph.addEdge(15, 12, 10);
    graph.addEdge(15, 2, 10);
    graph.addEdge(16, 2, 10);

    graph.addEdge(11, 13, 20);
    graph.addEdge(11, 12, 10);
    graph.addEdge(14, 13, 30);
    graph.addEdge(18, 13, 30);
    graph.addEdge(14, 18, 10);

}

void MainWindow::initButtons() {
    buttons = new MyButton * [SITES+1];
    buttons[1] = ui->pushButton_ALibrary1;
    buttons[2] = ui->pushButton_Bathroom2;
    buttons[3] = ui->pushButton_Block13;
    buttons[4] = ui->pushButton_Block24;
    buttons[5] = ui->pushButton_Block35;
    buttons[6] = ui->pushButton_Block46;
    buttons[7] = ui->pushButton_Block57;
    buttons[8] = ui->pushButton_DiningHall8;
    buttons[9] = ui->pushButton_Door19;
    buttons[10] = ui->pushButton_Door210;
    buttons[11] = ui->pushButton_Dorm111;
    buttons[12] = ui->pushButton_Dorm212;
    buttons[13] = ui->pushButton_Dorm313;
    buttons[14] = ui->pushButton_Dorm414;
    buttons[15] = ui->pushButton_Dorm515;
    buttons[16] = ui->pushButton_Dorm616;
    buttons[17] = ui->pushButton_Experiment17;
    buttons[18] = ui->pushButton_Gym18;
    buttons[19] = ui->pushButton_Office19;
    buttons[20] = ui->pushButton_RKeyan20;
    buttons[21] = ui->pushButton_SJiaoyan21;
    buttons[22] = ui->pushButton_TJiaoxue22;

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
