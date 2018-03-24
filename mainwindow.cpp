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

///////////////////////////////////////////

void MainWindow::onButtonClick(int id) {

    clearPath();
    if (selectStatus == 0) {
        initInfoPanel(buttons[id]);
        return;
    }
    hideInfoPanel();

    if (selectStatus == 1 || selectStatus == 2) {

        if (select1 == 0)
            select1 = id;
        else {
            if (select1 == id)
                return;
            select2 = id;
            drawPath();
            initSelect(0, 0, 0);
        }
        return;
    }
    //3



}

void MainWindow::drawPath() {
    if (selectStatus == 2) {

        return;
    }
    int * dist = new int[SITES+1];
    int * pres = new int[SITES+1];
    graph->shortestPaths(select1, dist, pres);

    QList<QPoint> points;
    int i = select2;
    while (pres[i] != select1) {
        points.insert(0, QPoint(pres[i], i));
        i = pres[i];
    }
    points.insert(0, QPoint(pres[i], i)); //is : 3, 6 - 6, 2 - 2, 5
    QList<QList<QPoint>> l;
    l.append(points);
    ui->labelBackground->drawPath(l);

    delete[] dist;
    delete[] pres;
}

void MainWindow::clearPath() {
    ui->labelBackground->drawPath(QList<QList<QPoint>>());
}

void MainWindow::mouseReleaseEvent(QMouseEvent *) {
    hideInfoPanel();
}

void MainWindow::on_pushButtonShortest_clicked()
{
    hideInfoPanel();
    if (ui->pushButtonShortest->text() == ShortestPath) {
        clearPath();
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


void MainWindow::on_pushButton_Clear_clicked() {
    ui->textEditSearch->clear();
}



void MainWindow::on_button_fang_da_clicked() {
    ui->frameSearch->hide();
    ui->frameSearch_2->show();
    ui->textEdit_2->setText(ui->textEditSearch->toPlainText());
    ui->textEdit->clear();
}

void MainWindow::on_close_search_clicked() {
    ui->frameSearch->show();
    ui->frameSearch_2->hide();
    ui->textEditSearch->clear();
}

void MainWindow::on_button_go_clicked()
{

}

