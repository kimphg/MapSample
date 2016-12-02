#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPaintEvent>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    map = new CMap(this);
    map->setCenterPos(21.036264,105.774866);
    map->setScaleRatio(16);
    //map->setWidthHeight(400,300);
    map->setPath("C:/Users/LamPT/Desktop/mapData");
    map->invalidate();
    map->UpdateImage();
    this->setGeometry(0,0,1024,1024);
}
void MainWindow::paintEvent(QPaintEvent * e)
{
    QPainter p(this);
    p.drawPixmap( (e->rect()),*(map->getImage()));
}
MainWindow::~MainWindow()
{
    delete ui;
}
