#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setFixedSize(1028,597);
    ui->setupUi(this);
    ui->frameLogin->hide();
    ui->frameSearch_2->hide();

    isAdmin = 0;

    initButtons();
    initGraph();
}

MainWindow::~MainWindow()
{
    delete graph;
    delete [] buttons;
    delete ui;
}

void MainWindow::initGraph() {
    graph = new AdjacencyWGraph(SITES);

    graph->addEdge(1, 12, 80);
    graph->addEdge(1, 21, 30);
    graph->addEdge(1, 20, 40);
    graph->addEdge(1, 3, 40);
    graph->addEdge(1, 22, 50);

    graph->addEdge(22, 21, 60);
    graph->addEdge(21, 17, 10);
    graph->addEdge(12, 21, 90);
    graph->addEdge(20, 21, 50);
    graph->addEdge(21, 3, 50);

    graph->addEdge(17, 10, 10);
    graph->addEdge(10, 20, 10);
    graph->addEdge(9, 10, 15);

    graph->addEdge(20, 22, 15);
    graph->addEdge(20, 3, 10);
    graph->addEdge(20, 12, 65);

    graph->addEdge(22, 9, 25);
    graph->addEdge(22, 19, 20);
    graph->addEdge(22, 7, 15);
    graph->addEdge(22, 3, 15);
    graph->addEdge(22, 12, 80);

    graph->addEdge(8, 9, 55);
    graph->addEdge(7, 9, 25);
    graph->addEdge(19, 9, 30);
    graph->addEdge(8, 19, 20);
    graph->addEdge(8, 13, 30);

    graph->addEdge(7, 19, 15);
    graph->addEdge(11, 19, 15);
    graph->addEdge(7, 6, 5);
    graph->addEdge(6, 5, 5);
    graph->addEdge(4, 5, 5);
    graph->addEdge(4, 3, 5);
    graph->addEdge(3, 12, 65);

    graph->addEdge(15, 12, 10);
    graph->addEdge(15, 2, 10);
    graph->addEdge(16, 2, 10);

    graph->addEdge(11, 13, 20);
    graph->addEdge(11, 12, 10);
    graph->addEdge(14, 13, 30);
    graph->addEdge(18, 13, 30);
    graph->addEdge(14, 18, 10);


}

void MainWindow::initButtons() {
    selectStatus = 0;
    select1 = 0;
    select2 = 0;
    buttons = new MyButton * [SITES+1];
    ui->labelBackground->buttons = buttons;

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

void MainWindow::onButtonClick(int id) {

    if (selectStatus == 0) {
        initInfoPanel(buttons[id]);
        return;
    }
    hideInfoPanel();

    if (selectStatus == 1) {

        if (select1 == 0) {
            select1 = id;
        }else {
            if (select1 == id)
                return;
            select2 = id;
            drawPath();
            //draw & repaint
            initSelect(0, 0, 0);
        }

    } else  {


    }


}


void MainWindow::drawPath() {
    int * dist = new int[SITES+1];
    int * pres = new int[SITES+1];
    graph->shortestPaths(select1, dist, pres);

    //int i = select2;
    //QList<int> list;
    //list.append(select2);
    //while (pres[i] != select1) {
        //i = pres[i];
      //  list.insert(0, i);
    //}
    //list.insert(0, select1); //is : 3 - 6 - 2 - 5

    QList<QPoint> points;
    int i = select2;
    while (pres[i] != select1) {
        points.insert(0, QPoint(pres[i], i));
        i = pres[i];
    }
    points.insert(0, QPoint(pres[i], i)); //is : 3, 6 - 6, 2 - 2, 5
    ui->labelBackground->drawPath(points);

    delete[] dist;
    delete[] pres;
}

void MainWindow::mouseReleaseEvent(QMouseEvent *) {
    hideInfoPanel();
}



void MainWindow::on_pushButtonShortest_clicked()
{
    hideInfoPanel();
    if (ui->pushButtonShortest->text() == ShortestPath) {
        //clear path
        initSelect(1, 0, 0);
    } else {
        initSelect(0, 0, 0);
    }
}

void MainWindow::initInfoPanel(MyButton * but) {
    int x0 = but->x();
    int y0 = but->y();
    ui->infoPanel->move(x0+17, y0+17);

    ui->buttonID->setText(QString("%1").arg(but->id));
    ui->buttonName->setText(but->name);
    ui->buttonInfo->setText(but->info);

    ui->buttonName->setEnabled(isAdmin);
    ui->buttonInfo->setEnabled(isAdmin);

}

void MainWindow::hideInfoPanel() {
    ui->infoPanel->move(-200, 100);
}

void MainWindow::initSelect(int status, int s1, int s2) {
    selectStatus = status;
    select1 = s1;
    select2 = s2;
    if (status == 1)
        ui->pushButtonShortest->setText(Selecting);
    else if (status == 0) {
        ui->pushButtonShortest->setText(ShortestPath);
    }

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

/////////////////////////////////////////
void MainWindow::on_pushButton_ALibrary1_clicked()
{
    onButtonClick(1);
}

void MainWindow::on_pushButton_Bathroom2_clicked()
{
onButtonClick(2);
}

void MainWindow::on_pushButton_Block13_clicked()
{
onButtonClick(3);
}

void MainWindow::on_pushButton_Block24_clicked()
{
onButtonClick(4);
}

void MainWindow::on_pushButton_Block35_clicked()
{
onButtonClick(5);
}

void MainWindow::on_pushButton_Block46_clicked()
{
onButtonClick(6);
}

void MainWindow::on_pushButton_Block57_clicked()
{
onButtonClick(7);
}

void MainWindow::on_pushButton_DiningHall8_clicked()
{
onButtonClick(8);
}

void MainWindow::on_pushButton_Door19_clicked()
{
onButtonClick(9);
}

void MainWindow::on_pushButton_Door210_clicked()
{
onButtonClick(10);
}

void MainWindow::on_pushButton_Dorm111_clicked()
{
onButtonClick(11);
}

void MainWindow::on_pushButton_Dorm212_clicked()
{
onButtonClick(12);
}

void MainWindow::on_pushButton_Dorm313_clicked()
{
onButtonClick(13);
}

void MainWindow::on_pushButton_Dorm414_clicked()
{
onButtonClick(14);
}

void MainWindow::on_pushButton_Dorm515_clicked()
{
onButtonClick(15);
}

void MainWindow::on_pushButton_Dorm616_clicked()
{
onButtonClick(16);
}

void MainWindow::on_pushButton_Experiment17_clicked()
{
onButtonClick(17);
}

void MainWindow::on_pushButton_Gym18_clicked()
{
onButtonClick(18);
}

void MainWindow::on_pushButton_Office19_clicked()
{
onButtonClick(19);
}

void MainWindow::on_pushButton_RKeyan20_clicked()
{
onButtonClick(20);
}

void MainWindow::on_pushButton_SJiaoyan21_clicked()
{
onButtonClick(21);
}

void MainWindow::on_pushButton_TJiaoxue22_clicked()
{
onButtonClick(22);
}


