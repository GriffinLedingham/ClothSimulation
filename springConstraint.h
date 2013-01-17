#ifndef springConstraint_H
#define springConstraint_H
#include "massPoint.h"

class springConstraint
{
public:
    springConstraint(massPoint *p1, massPoint *p2);
    springConstraint();
    void calculateConstraint();
protected:
    float restLength; // the length between massPoint p1 and p2 in rest configuration
    massPoint *p1, *p2;
};

#endif // springConstraint_H
