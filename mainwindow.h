#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "AdjacencyWGraph.hpp"
#include <QMainWindow>
#include "mybutton.h"

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
    AdjacencyWGraph<int> graph;



private slots:
    void on_pushButtonLibrary_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_Clear_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    void initButtons();
    void initGraph();
};

#endif // MAINWINDOW_H
