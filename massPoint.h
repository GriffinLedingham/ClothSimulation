#ifndef massPoint_H
#define massPoint_H
#include <QVector3D>

class massPoint
{
public:
    QVector3D pos;
    QVector3D old_pos;
    QVector3D accel;
    int mass;
    bool allowMove;
    bool updated;
    QVector3D normalSum;

    massPoint(QVector3D pos);
    massPoint();

    void addPointGravity(QVector3D f);

    void timeStep();

    QVector3D getPos();

    void offsetPosition(const QVector3D v);
    QVector3D getNormal();
    void fixPosition();
};

#endif // massPoint_H
