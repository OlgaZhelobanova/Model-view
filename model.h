//используется model.cpp
//использует модель star.h
#pragma once
#define MODEL_H


#include <QAbstractTableModel>
#include <QString>
#include "star.h"

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyModel(QObject *parent);//для исходных данных
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;//для количества строк
    int columnCount(const QModelIndex &parent = QModelIndex()) const;//для количества столбцов
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;//считывает данные
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;//для заголовков
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);//устанавливает новые данные
    Qt::ItemFlags flags(const QModelIndex & index) const ;

    //инициализация методов добавления, удаления
    void AddStar(Star* star);
    void DeleteStar(int row);
private:
    QList<Star*> stars;
};
