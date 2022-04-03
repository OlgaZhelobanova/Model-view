#include "star.h"

Star::Star(QString ID, QString Name, QString Pleiad, QString Size, QString Distance, QString Coordinate, QObject *parent): QObject(parent)//конструктор
{
    id = ID;
    name = Name;
    pleiad = Pleiad;
    size = Size;
    distance = Distance;
    coordinate = Coordinate;

}

//реализация сеттеров
void Star::SetID(QString ID)
{
    id = ID;
}
void Star::SetName(QString Name)
{
    name = Name;
}
void Star::SetPleiad(QString Pleiad)
{
    pleiad = Pleiad;
}
void Star::SetSize(QString Size)
{
    size = Size;
}
void Star::SetDistance(QString Distance)
{
    distance = Distance;
}
void Star::SetCoordinate(QString Coordinate)
{
    coordinate = Coordinate;
}

//реализация геттеров
QString Star::ID()
{
    return id;
}
QString Star::Name()
{
    return name;
}
QString Star::Pleiad()
{
    return pleiad;
}
QString Star::Size()
{
    return size;
}
QString Star::Distance()
{
    return distance;
}
QString Star::Coordinate()
{
    return coordinate;
}

//QStringList Star::GetFaculties()//для комбобокса
//{
//    QStringList value;
//    value.append("ИВТФ");
//    value.append("ИФФ");
//    value.append("ФЭУ");
//    return value;
//}

 Star::~Star()//деструктор
{
}
