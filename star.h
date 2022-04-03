//используется star.cpp
#ifndef STAR_H
#define STAR_H

#include "QString"
#include <QObject>

class Star: public QObject
{
    Q_OBJECT

public://методы
    Star(QString ID, QString Name, QString Pleiad, QString Size, QString Distance, QString Coordinate, QObject *parent = nullptr );//сеттеры
    ~Star();
    void SetID(QString ID);
    void SetName(QString Name);
    void SetPleiad(QString Pleiad);
    void SetSize(QString Size);
    void SetDistance(QString Distance);
    void SetCoordinate(QString Coordinate);


    QString ID();//геттеры
    QString Name();
    QString Pleiad();
    QString Size();
    QString Distance();
    QString Coordinate();
//    static QStringList GetFaculties();//???

private://свойства
    QString id;
    QString name;
    QString pleiad;
    QString size;
    QString distance;
    QString coordinate;
};

#endif // STAR_H
