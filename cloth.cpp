#include <QVector3D>
#include <OpenGL.h>
#include <OpenGL/gl.h>
#include "cloth.h"

extern int verticalSpringCount; //how many vertical springConstraints in the cloth
extern int horizontalSpringCount; //how many horizontal springConstraints in the cloth
extern int springConstraintCalculations;
extern bool colorFlagUSA, colorFlagGermany;

//draws each triangle of the cloth seperately
void cloth::drawTriangle(massPoint *p1, massPoint *p2, massPoint *p3, const QVector3D color)
{
    glColor3fv( (GLfloat*) &color );

    glNormal3fv((GLfloat *) &(p1->getNormal().normalized() ));
    glVertex3fv((GLfloat *) &(p1->getPos() ));

    glNormal3fv((GLfloat *) &(p2->getNormal().normalized() ));
    glVertex3fv((GLfloat *) &(p2->getPos() ));

    glNormal3fv((GLfloat *) &(p3->getNormal().normalized() ));
    glVertex3fv((GLfloat *) &(p3->getPos() ));

}



cloth::cloth(float width, float height)
{
    massPoints.resize(verticalSpringCount*horizontalSpringCount);

    for(int i=0;i<verticalSpringCount;i++)//i: x coordinate in array
    {
        for(int j = 0;j<horizontalSpringCount;j++)//j: y coordinate in array
        {
            //create/place each mass point into array based on dimensions of cloth
            QVector3D pos = QVector3D(width*(i/(float)verticalSpringCount),-height*(j/(float)horizontalSpringCount),0);
            massPoints[i + j*verticalSpringCount] = massPoint(pos);
        }
    }

    //push grid springConstraints into array (vector) to form springConstraint grid
    for(int i = 0;i<verticalSpringCount;i++)
    {
        for(int j = 0;j<horizontalSpringCount;j++)
        {
            if(i<verticalSpringCount-1)
            {
                springConstraints.append(springConstraint(getmassPoint(i,j),getmassPoint(i+1,j)));
            }
            if(j<horizontalSpringCount-1)
            {
                springConstraints.append(springConstraint(getmassPoint(i,j),getmassPoint(i,j+1)));
            }
            if(i<verticalSpringCount-1 && j<horizontalSpringCount-1)
            {
                springConstraints.append(springConstraint(getmassPoint(i,j),getmassPoint(i+1,j+1)));
            }
            if(i<verticalSpringCount-1 && j<horizontalSpringCount-1)
            {
                springConstraints.append(springConstraint(getmassPoint(i+1,j),getmassPoint(i,j+1)));
            }
        }
    }

    //push contraint springConstraints into array (vector) to connect springConstraints who are not direct neighbors
    for(int i = 0;i<verticalSpringCount;i++)
    {
        for(int j = 0;j<horizontalSpringCount;j++)
        {
            if(i<verticalSpringCount-2)
            {
                springConstraints.append(springConstraint(getmassPoint(i,j),getmassPoint(i+2,j)));
            }
            if(j<horizontalSpringCount-2)
            {
                springConstraints.append(springConstraint(getmassPoint(i,j),getmassPoint(i,j+2)));
            }
            if(i<verticalSpringCount-2 && j<horizontalSpringCount-2)
            {
                springConstraints.append(springConstraint(getmassPoint(i,j),getmassPoint(i+1,j+2)));
            }
            if(i<verticalSpringCount-2 && j<horizontalSpringCount-2)
            {
                springConstraints.append(springConstraint(getmassPoint(i+2,j),getmassPoint(i,j+2)));
            }
        }
    }

    //third group of neighboring contraints, looks too springConstrainty => bad
    /*for(int i = 0;i<verticalSpringCount;i++)
    {
        for(int j = 0;j<horizontalSpringCount;j++)
        {
            if(i<verticalSpringCount-3)
            {
                springConstraints.append(springConstraint(getmassPoint(i,j),getmassPoint(i+3,j)));
            }
            if(j<horizontalSpringCount-3)
            {
                springConstraints.append(springConstraint(getmassPoint(i,j),getmassPoint(i,j+3)));
            }
            if(i<verticalSpringCount-3 && j<horizontalSpringCount-3)
            {
                springConstraints.append(springConstraint(getmassPoint(i,j),getmassPoint(i+1,j+3)));
            }
            if(i<verticalSpringCount-3 && j<horizontalSpringCount-3)
            {
                springConstraints.append(springConstraint(getmassPoint(i+3,j),getmassPoint(i,j+3)));
            }
        }
    }*/

    //fix the end points' position to simulate a flying flag

    getmassPoint(0,0)->fixPosition();
    getmassPoint(1,0)->fixPosition();
    getmassPoint(2,0)->fixPosition();


    getmassPoint(0,horizontalSpringCount-1)->fixPosition();
    getmassPoint(0,horizontalSpringCount-2)->fixPosition();
    getmassPoint(0,horizontalSpringCount-3)->fixPosition();

}

void cloth::drawCloth()
{
    //zero the normals already used
    for(int i=0;i<massPoints.size();i++)
    {
        massPoints[i].normalSum = QVector3D(0,0,0);
    }

    //add all triangle normals to every mass point that is in a triangle
    for(int x = 0; x<verticalSpringCount-1; x++)
    {
        for(int y=0; y<horizontalSpringCount-1; y++)
        {
            QVector3D normal = getTriNormals(getmassPoint(x+1,y+1),getmassPoint(x+1,y),getmassPoint(x,y+1));
            getmassPoint(x+1,y)->normalSum += normal;
            getmassPoint(x,y+1)->normalSum += normal;
            getmassPoint(x+1,y+1)->normalSum += normal;

            normal = getTriNormals(getmassPoint(x+1,y),getmassPoint(x,y),getmassPoint(x,y+1));
            getmassPoint(x,y)->normalSum += normal;
            getmassPoint(x+1,y)->normalSum += normal;
            getmassPoint(x,y+1)->normalSum += normal;
        }
    }

    //color the triangles, and then draw them (the drawing of an american flag: the canadian one was far too difficult to do without textures)
    glBegin(GL_TRIANGLES);
    for(int x = 0; x<verticalSpringCount-1; x++)
    {
        for(int y=0; y<horizontalSpringCount-1; y++)
        {
            QVector3D color(1,1,1);
            if(colorFlagUSA)
            {
                if(y<(horizontalSpringCount/2)+1 && x<(verticalSpringCount/2)+1)
                {
                    if(x%2 && y%2)
                    {
                        color = QVector3D(1,1,1);
                    }
                    else
                    {
                        color = QVector3D(0.0f,0.0f,.7f);
                    }
                }
                else if(y%3)
                {
                    color = QVector3D(1.0f,.0f,0.0f);
                }
                else
                {
                    color = QVector3D(1,1,1);
                }
            }
            else if(colorFlagGermany)
            {
                if(y<(horizontalSpringCount/3))
                {
                    color = QVector3D(0.0f,0.0f,.0f);
                }
                else if(y>=(horizontalSpringCount/3) && y<=2*(horizontalSpringCount/3))
                {
                    color = QVector3D(1.0f,.0f,.0f);
                }
                else if(y>2*(horizontalSpringCount/3))
                {
                    color = QVector3D(1.0f,.8f,0.0f);
                }
            }
            drawTriangle(getmassPoint(x+1,y),getmassPoint(x,y),getmassPoint(x,y+1),color);//upper left triangle
            drawTriangle(getmassPoint(x+1,y+1),getmassPoint(x+1,y),getmassPoint(x,y+1),color);//lower right triangle
        }
    }
    glEnd();
}

void cloth::timeStep()
{
    //iterate over all springConstraints, calculating constraints as often as specified in UI (increases smoothness)
    for(int i=0; i<springConstraintCalculations; i++)
    {
        for(int j=0;j<springConstraints.size();j++)
        {
            springConstraints[j].calculateConstraint();
        }
    }

    //after all constraints
    for(int i = 0; i<massPoints.size(); i++)
    {
        massPoints[i].timeStep();
    }
}

//calculates the normal vector of an input triangle
QVector3D cloth::getTriNormals(massPoint *p1,massPoint *p2,massPoint *p3)
{
    QVector3D pos1 = p1->getPos();
    QVector3D pos2 = p2->getPos();
    QVector3D pos3 = p3->getPos();
    QVector3D v1 = pos2-pos1;
    QVector3D v2 = pos3-pos1;

    return QVector3D::crossProduct(v1,v2);
}

//split the cloth into individual trinagles to calculate the wind on the flag
void cloth::triWindForce(massPoint *p1,massPoint *p2,massPoint *p3, const QVector3D direction)
{
    QVector3D normal = getTriNormals(p1,p2,p3);
    QVector3D d = normal.normalized();

    QVector3D force = normal*(QVector3D::dotProduct(d,direction));

    p1->accel += force*p1->mass;
    p2->accel += force*p2->mass;
    p3->accel += force*p3->mass;
}

//update the acceleration vector of each mass point after applying input force
void cloth::addPointGravity(const QVector3D direction)
{

    for(int i = 0; i<massPoints.size(); i++)
    {
        massPoints[i].addPointGravity(direction);
    }

}

//update the points in each triangle, applying wind force to each individual mass point
void cloth::windForce(const QVector3D direction)
{
    for(int i = 0; i<verticalSpringCount-1; i++)
    {
        for(int j=0; j<horizontalSpringCount-1; j++)
        {
            triWindForce(getmassPoint(i+1,j),getmassPoint(i,j),getmassPoint(i,j+1),direction);

            triWindForce(getmassPoint(i+1,j+1),getmassPoint(i+1,j),getmassPoint(i,j+1),direction);
        }
    }
}

//returns the address of the requested mass point
massPoint* cloth::getmassPoint(int i, int j)
{
    return &massPoints[i+j*verticalSpringCount];
}

