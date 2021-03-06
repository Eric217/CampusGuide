#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "AdjacencyWGraph.h"
#include <QMainWindow>
#include "DrawLabel.h"

#define ShortestPath QString("最短路径")
#define Selecting QString("取消选择")
#define AllPaths QString("全部路径")


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    MyButton ** buttons;
    AdjacencyWGraph * graph;

protected:
    void mouseReleaseEvent(QMouseEvent *);

private:
    Ui::MainWindow *ui;

    bool isAdmin;

    ///状态0:正常，状态1:选两个点最短路径 状态2:选两个点全部路径
    int selectStatus;
    int select1;
    int select2;

    void initButtons();
    void initGraph();
    void onButtonClick(int id);
    void initSelect(int status, int s1, int s2);
    void initInfoPanel(MyButton *);
    void hideInfoPanel();
    void drawPath();

private slots:
    void on_pushButtonLibrary_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_Clear_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_ALibrary1_clicked();

    void on_pushButton_Bathroom2_clicked();

    void on_pushButton_Block13_clicked();

    void on_pushButton_Block24_clicked();

    void on_pushButton_Block35_clicked();

    void on_pushButton_Block46_clicked();

    void on_pushButton_Block57_clicked();

    void on_pushButton_DiningHall8_clicked();

    void on_pushButton_Door19_clicked();

    void on_pushButton_Door210_clicked();

    void on_pushButton_Dorm111_clicked();

    void on_pushButton_Dorm212_clicked();

    void on_pushButton_Dorm515_clicked();

    void on_pushButton_Dorm313_clicked();

    void on_pushButton_Dorm414_clicked();

    void on_pushButton_Dorm616_clicked();

    void on_pushButton_Experiment17_clicked();

    void on_pushButton_Gym18_clicked();

    void on_pushButton_Office19_clicked();

    void on_pushButton_RKeyan20_clicked();

    void on_pushButton_SJiaoyan21_clicked();

    void on_pushButton_TJiaoxue22_clicked();

    void on_pushButtonShortest_clicked();


};

#endif // MAINWINDOW_H
