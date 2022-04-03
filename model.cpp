#include "model.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{

    Star* str1 = new Star("101","Бетельгейзе","Орион", "красный гигант", "548 св.лет", "+8/44", this);
    Star* str2 = new Star("102","Вега","Лира", "белый гигант", "25.3 св.лет", "+19/27", this);
    Star* str3 = new Star("103","Сириус Б","Большой Пес", "белый карлик", "8.6 св.лет", "+38/44", this);
    AddStar(str1);
    AddStar(str2);
    AddStar(str3);
}

int MyModel::rowCount(const QModelIndex &) const
{
   return stars.count();
}

int MyModel::columnCount(const QModelIndex &) const
{
    return 6;
}


QVariant MyModel::data(const QModelIndex &index, int role) const //для редактирования - считывает значения
{
    if (role == Qt::DisplayRole)
    {
        QString Value = "";
        Star* str = stars.at(index.row());
        if (index.column() == 0){Value = str->ID();}
        else if (index.column() == 1){Value = str->Name();}
        else if (index.column() == 2){Value = str->Pleiad();}
        else if (index.column() == 3){Value = str->Size();}
        else if (index.column() == 4){Value = str->Distance();}
        else if (index.column() == 5){Value = str->Coordinate();}
        else {Value = "";};
       return Value;
    }
    return QVariant();
}


QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Name");
            case 2:
                return QString("Pleiad");
            case 3:
                return QString("Size");
            case 4:
                return QString("Distance");
            case 5:
                return QString("Coordinate");
            }
        }
    }
    return QVariant();
}


bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)//устанавливает значения
{
   if (role == Qt::EditRole)
    {
        Star* str = stars.at(index.row());
        if (index.column() == 0){str->SetID(value.toString());}
        else if (index.column() == 1){str->SetName(value.toString());}
        else if (index.column() == 2){str->SetPleiad(value.toString());}
        else if (index.column() == 3){str->SetSize(value.toString());}
        else if (index.column() == 4){str->SetDistance(value.toString());}
        else if (index.column() == 5){str->SetCoordinate(value.toString());}
    }

    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}




void MyModel::AddStar(Star* star)
{
    beginInsertRows(QModelIndex(),stars.size(),stars.size());
    stars.append(star);//добавляет индекс в список
    endInsertRows();

}

void MyModel::DeleteStar(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    stars.removeAt(row);//удаляет индекс из списка
    endRemoveRows();

}
