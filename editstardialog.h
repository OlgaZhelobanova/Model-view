#ifndef EDITSTARDIALOG_H
#define EDITSTARDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "star.h"

class EditStarDialog : public QDialog
{
  Q_OBJECT

private:
    QLineEdit* editID;
    QLineEdit* editName;
    //можно сделать combobox
    QLineEdit* editPleiad;
    QLineEdit* editSize;
    QLineEdit* editDistance;
    QLineEdit* editCoordinate;

public:
    EditStarDialog(QWidget* pwgt = nullptr);

    QString id() const;
    QString name() const;
    QString pleiad() const;
    QString size() const;
    QString distance() const;
    QString coordinate() const;


    void SetUpDialog(QString id, QString name,QString pleiad, QString size, QString distance,QString coordinate);
};

#endif // EDITSTARDIALOG_H
