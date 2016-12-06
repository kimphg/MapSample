#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cmap.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    CMap *map;
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *);
    void keyPressEvent(QKeyEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
private:
    Ui::MainWindow *ui;
    QPoint *pointCLick;
    bool releaseMouse;
};

#endif // MAINWINDOW_H
