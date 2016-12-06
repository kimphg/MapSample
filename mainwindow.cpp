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
    this->setGeometry(100,100,1024,768);
    pressed = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent * e)
{
    QPainter p(this);
    p.drawPixmap( (e->rect()),*(map->getImage()));
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    map->setWidthHeight(width(), height());
    map->invalidate();
    map->UpdateImage();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() != Qt::Key_Z )
    {
        return;
    }
    else{
        int zoom = (int) map->getScaleRatio();
        switch(zoom)
        {
        case 14: map->setScaleRatio(15);
            break;
        case 15: map->setScaleRatio(16);
            break;
        case 16: map->setScaleRatio(14);
            break;
        default: map->setScaleRatio(15);
            break;
        }

        map->invalidate();
        map->UpdateImage();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(press)
    {

    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() != Qt::LeftButton)
    {
        return;
    }

    pressed = true;
    pressPos = e->pos();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    map->invalidate();
    map->UpdateImage();
}
