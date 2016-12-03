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
    //map->setPath("D:/DOWN/MapData/OpenStreetMap");
    map->setPath("D:/DOWN/MapData/ThunderForest");
    map->invalidate();
    map->UpdateImage();
    this->setGeometry(10,10,1024,768);
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
