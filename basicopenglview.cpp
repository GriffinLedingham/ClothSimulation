#include "basicopenglview.h"
#include <QTimer>
#include <cmath>
#include "cloth.h"
#include <OpenGL/glu.h>
#include <OpenGL.h>

extern float timestep;
extern bool mFor, mBack, mLeft, mRight, cUp, cDown, cLeft, cRight, cJump, cFall;
extern float windX;
extern int horizontalSpringCount,verticalSpringCount;
extern float windY;
extern float windZ;
extern int flagWidth,flagHeight;
float cameraZ = 45.0f;
float cameraX = 0.0f;
float cameraY = 5.0f;
float cameraRotHor = 180.0f;
float cameraRotVer = 10.0f;
QVector3D gravityVector = QVector3D(0.0f,-0.1f,0.0f);

cloth cloth1(flagWidth,flagHeight); // one Cloth object of the Cloth class

BasicOpenGLView::BasicOpenGLView(QWidget *parent) :
    QGLWidget(parent),
    projectionMatrix(),
    viewMatrix()
{
}

void BasicOpenGLView::resizeCloth()
{
    cloth1 = cloth(flagWidth,flagHeight);



}

void BasicOpenGLView::initializeGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);



    //Timer which updates the GL render.
    QTimer *timer = new QTimer();
    timer->start(1); //time in ms, here 17 ms
    connect(timer ,SIGNAL(timeout()),this,SLOT(paintGL()));

    //Timer which updates the scene objects.
    QTimer *animate = new QTimer();
    animate->start(1); //time in ms, here 1000 ms
    connect(timer ,SIGNAL(timeout()),this,SLOT(animateGL()));

    glShadeModel(GL_SMOOTH);
    //glClearColor(0.2f, 0.2f, 0.4f, 0.5f);
    glClearDepth(1.0f);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_COLOR_MATERIAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glEnable(GL_LIGHT0);
    GLfloat lightPos[4] = {-1.0,1.0,0.5,0.0};
    glLightfv(GL_LIGHT0,GL_POSITION,(GLfloat *) &lightPos);

    glEnable(GL_LIGHT1);

    GLfloat lightPos1[4] = {1.0,0.0,-0.2,0.0};
    GLfloat lightAmbient1[4] = {0.0,0.0,0.0,0.0};
    GLfloat lightDiffuse1[4] = {0.5,0.5,0.5,0.0};

    glLightfv(GL_LIGHT1,GL_POSITION,(GLfloat *) &lightPos1);
    glLightfv(GL_LIGHT1,GL_AMBIENT,(GLfloat *) &lightAmbient1);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,(GLfloat *) &lightDiffuse1);

    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);
}

float ball_time = 0; // counter for used to calculate the z position of the ball below


void BasicOpenGLView::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    float newWindX = (float)rand()/((float)RAND_MAX/windX);
    float newWindY = (float)rand()/((float)RAND_MAX/windY);
    float newWindZ = (float)rand()/((float)RAND_MAX/windZ);

    //arbitrary gravity value
    cloth1.addPointGravity(gravityVector*timestep);
    cloth1.windForce(QVector3D(newWindX,newWindY,newWindZ)*timestep);
    cloth1.timeStep();

    // drawing
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glColor3f(0.9f,1.0f,.9f);
    glVertex3f(-200.0f,-100.0f,-100.0f);
    glVertex3f(200.0f,-100.0f,-100.0f);
    glColor3f(0.4f,0.8f,0.4f);
    glVertex3f(200.0f,100.0f,-100.0f);
    glVertex3f(-200.0f,100.0f,-100.0f);
    glEnd();
    glEnable(GL_LIGHTING);

    //glPushMatrix();
    viewMatrix.setToIdentity();
    viewMatrix.rotate(cameraRotVer,1,0,0);
    viewMatrix.rotate(cameraRotHor,0,1,0);

    viewMatrix.translate(cameraX,cameraY,cameraZ);
    viewMatrix.lookAt(QVector3D(0.0,3.0,-15.0),
                      QVector3D(0.0,4.0,0.0),
                      QVector3D(0.0,1.0,0.0));
    glLoadMatrixd(viewMatrix.data());

    glPushMatrix();
    glTranslatef(-0.7f, 0.0f, -.1f);
    glRotatef(90,1,0,0);
    glColor3f(1,1,1);

    //flag pole
    GLUquadricObj *quadric;
    quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL );
    gluCylinder(quadric,.8f,.8f,30,100,100);
    gluDeleteQuadric(quadric);
    glPopMatrix();

    //ground
    glBegin(GL_POLYGON);
    glColor3f(.4f,.4f,.4f);
    glVertex3f(20.0f,-30.0f,-20.0f);
    glVertex3f(-20.0f,-30.0f,-20.0f);
    glVertex3f(-20.0f,-30.0f,20.0f);
    glVertex3f(20.0f,0.-30.0f,20.0f);
    glEnd();



    cloth1.drawCloth();
    this->swapBuffers();
}

void BasicOpenGLView::animateGL()
{
    if(mFor == true)
    {
        cameraX = cameraX - sin((cameraRotHor*3.141592)/180);
        cameraZ = cameraZ + cos((cameraRotHor*3.141592)/180);

    }
    if(mBack == true)
    {
        cameraX = cameraX + sin((cameraRotHor*3.141592)/180)*.5;
        cameraZ = cameraZ - cos((cameraRotHor*3.141592)/180)*.5;

    }
    if(mLeft == true)
    {
        cameraX = cameraX - sin(((cameraRotHor-90)*3.141592)/180);
        cameraZ = cameraZ + cos(((cameraRotHor-90)*3.141592)/180);

    }
    if(mRight == true)
    {
        cameraX = cameraX - sin(((cameraRotHor+90)*3.141592)/180);
        cameraZ = cameraZ + cos(((cameraRotHor+90)*3.141592)/180);

    }

    //Key input to spin the camera, only if pong mode is disabled
    if(cLeft == true)
    {
        cameraRotHor -= 3;


    }
    if(cRight == true)
    {
        cameraRotHor += 3;


    }
    if(cUp == true)
    {
        cameraRotVer -= 3;


    }
    if(cDown == true)
    {
        cameraRotVer += 3;


    }

    //Pan camera up and down in the Y-Axis
    if(cJump == true)
    {
        cameraY -= 1;
    }
    if(cFall == true)
    {
        cameraY += 1;
    }

}

void BasicOpenGLView::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);

    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(60.0f,
                                 (float)w/(float)h,
                                 0.1,
                                 200.0);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(projectionMatrix.data());

    glMatrixMode(GL_MODELVIEW);
}
