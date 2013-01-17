#include "massPoint.h"
#include <QVector>
#include <QVector2D>
#include <QVector3D>

extern float timestep; //the timestep between frames

extern float damping; //springConstraint damping
QVector3D zeroVector = QVector3D(0,0,0);

massPoint::massPoint()
{

}

massPoint::massPoint(QVector3D pos)
{
    this->accel=zeroVector;
    this->normalSum=zeroVector;
    this->allowMove=true;
    this->updated=false;
    this->mass=1;
    this->old_pos=pos;
    this->pos=pos;
}


QVector3D massPoint::getNormal()
{
    return normalSum;
}

void massPoint::timeStep()
{
    if(allowMove)
    {
        QVector3D velocityVector = pos-old_pos;
        QVector3D temp = pos;
        //initial position = initial position + (directional acceleration from force * timestep) + velocity damped by damping constant
        pos = pos + accel*timestep + (1.0-damping)*(velocityVector);
        old_pos = temp;
        //instanataneous acceleration has been used, reset to 0
        accel = zeroVector;
    }
}

void massPoint::addPointGravity(QVector3D forceIn)
{
    accel += forceIn*mass;
}

QVector3D massPoint::getPos()
{
    return pos;
}

void massPoint::offsetPosition(const QVector3D v)
{
    if(allowMove)
    {
        pos += v;
    }
}

void massPoint::fixPosition()
{
    allowMove = false;
}

