#include "springConstraint.h"
#include "massPoint.h"

extern float timestep;
extern float damping;
extern int verticalSpringCount; //how many vertical springConstraints in the cloth
extern int horizontalSpringCount;

springConstraint::springConstraint()
{
}

springConstraint::springConstraint(massPoint *p1, massPoint *p2)
{
    QVector3D springConstraint = p1->getPos() - p2->getPos();
    this->p1 = p1;
    this->p2 = p2;

    restLength = springConstraint.length();
}

void springConstraint::calculateConstraint()
{
    QVector3D springConstraint = p2->getPos() - p1->getPos(); //springConstraint vector from p1 to p2
    float currLength = springConstraint.length(); //current springConstraint length
    QVector3D constrainVector = (springConstraint*(1 - restLength/currLength))/2; //bring both p1 and p2 back towards each other by one half (each) the constrain vector

        //it appears better to caclulate this AFTER all constraints have been individually calculated
        /*if(p1->allowMove && p1->updated == false)
        {
            QVector3D velocityVector = p1->pos-p1->old_pos;
            QVector3D temp = p1->pos;
            //initial position = initial position + (directional acceleration from force * timestep) + velocity damped by damping constant
            p1->pos = p1->pos + p1->accel*timestep + ((1.0-damping)*velocityVector) ;
            p1->old_pos = temp;
            //instanataneous acceleration has been used, reset to 0
            p1->accel = QVector3D(0,0,0);
            p1->updated=true;
        }

        if(p2->allowMove&& p2->updated==false)
        {
            QVector3D velocityVector = p2->pos-p2->old_pos;
            QVector3D temp = p2->pos;
            //initial position = initial position + (directional acceleration from force * timestep) + velocity damped by damping constant
            p2->pos = p2->pos + p2->accel*timestep + ((1.0-damping)*(velocityVector));
            p2->old_pos = temp;
            //instanataneous acceleration has been used, reset to 0
            p2->accel = QVector3D(0,0,0);
            p2->updated=true;
        }*/

    p1->offsetPosition(constrainVector); //send p1 out towards p2
    p2->offsetPosition(-constrainVector); //pull p2 back towards p1
}

