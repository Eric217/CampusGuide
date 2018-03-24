#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::on_saveChange_clicked() {

    if (addingSite) {


        return;
    }



    int id = ui->buttonID->text().toInt();
    QString s1 = ui->buttonName->toPlainText().trimmed();
    if (s1.isEmpty())
        return;
    for (int i = 1; i <= SITES; i++) {
        if (siteNames[i] == s1 && i != id)
            return;
    }
    siteNames[id] = s1;
    siteInfos[id] = ui->buttonInfo->toPlainText().trimmed();
    buttons[id]->setupContents(id, s1, siteInfos[id]);
    hideInfoPanel();
}

void MainWindow::on_deleteNode_clicked() {
    int id = ui->buttonID->text().toInt();
    graph->isolate(id);
    buttons[id]->hide();
    buttons[id]->setupContents(id, "__sa-mp_ma,e", "123");
    hideInfoPanel();
}

void MainWindow::on_loginStart_clicked()
{
    clearPath();
    hideFloatingWidgets();
    ui->frameLogin->show();
}


void MainWindow::on_multiPointConfirm_clicked() {
    int len = selectArr.size();
    if (len < 2)
        return;
    int * a = new int[len];
    for (int i = 0; i < len; i++) {
        a[i] = selectArr.first();
        selectArr.removeFirst();
    }
    QList<QList<QPoint>> list;
    list.append(graph->minSpanTree(a, len));
    ui->labelBackground->drawPath(list);
    setSelected(0, 0, 0);
    delete[] a;
}

void MainWindow::on_pushButtonShortest_clicked() {
    clickFuncs(1);
}

void MainWindow::on_pushButtonPoints_clicked() {
    clickFuncs(3);
}

void MainWindow::on_pushButtonAll_clicked() {
    clickFuncs(2);
}

void MainWindow::on_loginButton_clicked() {
    isAdmin = !isAdmin;
    if (isAdmin)
        ui->loginButton->setText("退出登陆");
    else
        ui->loginButton->setText("登陆");
    ui->frameLogin->hide();
}

void MainWindow::on_search2_closeButton_clicked() {
    ui->frameSearch->show();
    ui->frameSearch_2->hide();
    ui->textEditSearch->clear();
}

void MainWindow::on_loginCloseButton_clicked() {
    ui->frameLogin->hide();
}

void MainWindow::on_button_fang_da_clicked() {
    clearPath();
    ui->frameLogin->hide();
    setSelected(0, 0, 0);
    ui->frameSearch->hide();
    ui->frameSearch_2->show();
    ui->textEdit_2->setText(ui->textEditSearch->toPlainText());
    ui->textEdit->clear();
}


void MainWindow::on_pushButton_Clear_clicked() {
    ui->textEditSearch->clear();
}

void MainWindow::on_button_go_clicked() {
    QString s1 = ui->textEdit->toPlainText().trimmed();
    QString s2 = ui->textEdit_2->toPlainText().trimmed();
    if (s1.isEmpty() || s2.isEmpty())
        return;
    select1 = 0; select2 = 0;
    for (int i = 1; i <= SITES; i++) {
        if (siteNames[i] == s1 || siteNames[i] == s2) {
            if (!select1)
                select1 = i;
            else {
                select2 = i;
                selectStatus = 1;
                drawPath();
                setSelected(0, 0, 0);
            }

        }
    }

}

void MainWindow::hideInfoPanel() {
    ui->infoPanel->move(-200, 100);
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

    siteNames = new QString[SITES+1] {"", "图书馆","浴室","一区","二区","三区","四区",
            "五区","食堂","一号门","二号门","一号宿舍楼","二号宿舍楼","三号宿舍楼",
            "四号宿舍楼","五号宿舍楼","六号宿舍楼","实验楼",
            "室外运动场","办公楼","科研楼","教研楼","教学楼"};

    siteInfos = new QString[SITES+1] {"", "This is the only library", "Bathroom", "Block1",
            "Block2", "Block3", "Block4", "Block5", "DiningHall", "Door1", "Door2",
            "Dorm1", "Dorm2", "Dorm3", "Dorm4", "Dorm5", "Dorm6", "Experiment Building",
            "Gym", "Office", "ScienceOfExp", "ScienceOfTeach", "Teaching"};

    for (int i = 1; i <= SITES; i++)
        buttons[i]->setupContents(i, siteNames[i], siteInfos[i]);

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
