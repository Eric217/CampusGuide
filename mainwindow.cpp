#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setFixedSize(1028,597);
    ui->setupUi(this);

    ui->multiPointConfirm->hide();

    isAdmin = 0;
    hideFloatingWidgets();

    initButtons();
    initGraph();
}

MainWindow::~MainWindow()
{
    delete [] siteNames;
    delete [] buttons;
    delete ui;
    graph->Delete();
    //delete graph;
}

///////////////////////////////////////////

void MainWindow::onButtonClick(int id) {

    clearPath();
    if (selectStatus == 0) {
        moveInfoPanel(buttons[id]);
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
            setSelected(0, 0, 0);
        }
        return;
    }

    if (!selectArr.contains(id))
        selectArr.append(id);

}

void MainWindow::hideFloatingWidgets() {
    hideInfoPanel();
    ui->frameSearch_2->hide();
    ui->frameSearch->show();
    ui->frameLogin->hide();

}

void MainWindow::drawPath() {

    QList<QList<QPoint>> l;

    if (selectStatus == 2) {
        graph->findAllPath(select1, select2, l);


    } else {
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

        l.append(points);
        delete[] dist;
        delete[] pres;
    }

    ui->labelBackground->drawPath(l);
}

void MainWindow::clearPath() {
    ui->labelBackground->drawPath(QList<QList<QPoint>>());
}

void MainWindow::mouseReleaseEvent(QMouseEvent *) {
    clearPath();
    hideInfoPanel();
}

void MainWindow::clickFuncs(int type) {
    hideFloatingWidgets();
    if (selectStatus == 0) {
        clearPath();
        setSelected(type, 0, 0);
    } else
        setSelected(0, 0, 0);
}


void MainWindow::moveInfoPanel(MyButton * but) {
    int x0 = but->x();
    int y0 = but->y();
    ui->infoPanel->move(x0+17, y0+17);

    ui->buttonID->setText(QString("%1").arg(but->id));
    ui->buttonName->setText(but->name);
    ui->buttonInfo->setText(but->info);

    ui->buttonName->setEnabled(isAdmin);
    ui->buttonInfo->setEnabled(isAdmin);
    if (isAdmin)
        ui->adminPanel->show();
    else
        ui->adminPanel->hide();

}

void MainWindow::setSelected(int status, int s1, int s2) {
    selectStatus = status;
    select1 = s1;
    select2 = s2;
    ui->pushButtonShortest->setText(ShortestPath);
    ui->pushButtonAll->setText(AllPaths);
    ui->pushButtonPoints->setText(MultiPoints);
    ui->multiPointConfirm->hide();
    if (status == 1) {
        ui->pushButtonShortest->setText(Selecting);
    } else if (status == 2) {
        ui->pushButtonAll->setText(Selecting);
    } else if (status == 3) {
        ui->pushButtonPoints->setText(Selecting);
        ui->multiPointConfirm->show();
        selectArr.clear();
    }

}







