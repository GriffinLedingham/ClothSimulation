#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

bool mFor, mBack, mLeft, mRight, cUp, cDown, cLeft, cRight, cJump, cFall;
float windX=0.20f;
float windY=0.20f;
float windZ=0.01f;
float damping=.00f; //how much to damp the cloth simulation each frame
int springConstraintCalculations = 20; //how many springConstraint calculations occur each time step
bool colorFlagUSA=false;
bool colorFlagGermany=false;
int flagWidth = 14;
int flagHeight = 10;
float timestep=0.3f;

int verticalSpringCount = 16; //how many vertical springConstraints in the cloth
int horizontalSpringCount = 20; //how many horizontal springConstraints in the cloth
extern float cameraZ;
extern float cameraX;
extern float cameraY;
extern float cameraRotHor;
extern float cameraRotVer;


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_verticalSlider_valueChanged(int value)//windx
{
    windX=(float)value/100;
}

void MainWindow::on_verticalSlider_2_valueChanged(int value)//windy
{
    windY=(float)value/100;
}

void MainWindow::on_verticalSlider_3_valueChanged(int value)//windz
{
    windY=(float)value/100;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)//damping
{
    damping = (float)value/99;
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)//Vertical springConstraints
{

    verticalSpringCount = value;
    ui->widget->resizeCloth();
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)//Horizontal springConstraints
{
    horizontalSpringCount = value;
    ui->widget->resizeCloth();
}

void MainWindow::on_horizontalSlider_4_valueChanged(int value)//Number of springConstraint recalculations per frame
{
    springConstraintCalculations = value;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if(event->text() =="w")
    {
        mFor = true;
    }

    if(event->text() == "s")
    {
        mBack = true;
    }

    if(event->text() =="a")
    {
        mLeft = true;
    }

    if(event->text() == "d")
    {
        mRight = true;
    }

    if(event->text() == "-") //down
    {
        cFall = true;
    }

    if(event->text() == "=") //up
    {
        cJump = true;
    }

    if(event->key() == Qt::Key_Left) //rot left
    {
        cLeft = true;
    }

    if(event->key() == Qt::Key_Right) //rot right
    {
        cRight = true;
    }

    if(event->key() == Qt::Key_Up) //rot up
    {
        cUp = true;
    }

    if(event->key() == Qt::Key_Down) //rot down
    {
        cDown = true;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
    if(event->text() == "w")
    {
        mFor = false;
    }

    if(event->text() == "s")
    {
        mBack = false;
    }

    if(event->text() == "a")
    {
        mLeft = false;
    }

    if(event->text() == "d")
    {
        mRight = false;
    }

    if(event->text() == "-") //down
    {
        cFall = false;
    }

    if(event->text() == "=") //up
    {
        cJump = false;
    }

    if(event->key() == Qt::Key_Left) //rot left
    {
        cLeft = false;
    }

    if(event->key() == Qt::Key_Right) //rot right
    {
        cRight = false;
    }

    if(event->key() == Qt::Key_Up) //rot up
    {
        cUp = false;
    }

    if(event->key() == Qt::Key_Down) //rot down
    {
        cDown = false;
    }
}


void MainWindow::on_horizontalSlider_5_valueChanged(int value)//Flag pattern
{
    if(value==0)
    {
        colorFlagUSA = false;
        colorFlagGermany = false;
    }
    else if(value==1)
    {
        colorFlagUSA = true;
        colorFlagGermany = false;
    }
    else if(value==2)
    {
        colorFlagUSA = false;
        colorFlagGermany = true;
    }
}

void MainWindow::on_verticalSlider_4_valueChanged(int value)//Flag width
{
    flagWidth = value;
    ui->widget->resizeCloth();

}

void MainWindow::on_verticalSlider_5_valueChanged(int value)//Flag height
{
    flagHeight = value;
    ui->widget->resizeCloth();

}

void MainWindow::on_horizontalSlider_6_valueChanged(int value)//Timestep
{
    timestep = (float)value/100;
}
