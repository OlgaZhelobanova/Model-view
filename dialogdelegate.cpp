#include "dialogdelegate.h"
#include "QtWidgets"
#include "editstardialog.h"

DialogDelegate::DialogDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent)
{
    dparentWidget = parentWidget;

}


bool DialogDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                 const QStyleOptionViewItem &, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        EditStarDialog* editDialog = new EditStarDialog(dparentWidget);

        QString ID = model->data(model->index(index.row(),0,index)).toString();
        QString Name = model->data(model->index(index.row(),1,index)).toString();
        QString Pleiad = model->data(model->index(index.row(),2,index)).toString();
        QString Size = model->data(model->index(index.row(),3,index)).toString();
        QString Distance = model->data(model->index(index.row(),4,index)).toString();
        QString Coordinate = model->data(model->index(index.row(),5,index)).toString();


        editDialog->SetUpDialog(ID, Name, Pleiad, Size, Distance, Coordinate);
        if (editDialog->exec() == QDialog::Accepted)
        {
            model->setData(model->index(index.row(),0,index),editDialog->id());
            model->setData(model->index(index.row(),1,index),editDialog->name());
            model->setData(model->index(index.row(),2,index),editDialog->pleiad());
            model->setData(model->index(index.row(),3,index),editDialog->size());
            model->setData(model->index(index.row(),4,index),editDialog->distance());
            model->setData(model->index(index.row(),5,index),editDialog->coordinate());
        }

         editDialog->deleteLater();

    }
    return false;

}

QWidget *DialogDelegate::createEditor(QWidget* /* parent */,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    return nullptr;
}
