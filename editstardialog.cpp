#include "editstardialog.h"
#include "star.h"
EditStarDialog::EditStarDialog(QWidget* pwgt): QDialog(pwgt)
{
    editID = new QLineEdit();
    editName = new QLineEdit();
    editPleiad = new QLineEdit();
    editSize = new QLineEdit();
    editDistance = new QLineEdit();
    editCoordinate = new QLineEdit();

//    QStringList faculties = Student::GetFaculties(); //для комбобокса
//    foreach  (QString fc, faculties)
//    {
//        editFaculty->addItem(fc);
//    }

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel("ID"),1,1);
    mainLayout->addWidget(editID,1,2);
    mainLayout->addWidget(new QLabel("Название"),2,1);
    mainLayout->addWidget(editName,2,2);
    mainLayout->addWidget(new QLabel("Созвездие"),3,1);
    mainLayout->addWidget(editPleiad,3,2);
    mainLayout->addWidget(new QLabel("Размер"),4,1);
    mainLayout->addWidget(editSize,4,2);
    mainLayout->addWidget(new QLabel("Расстояние"),5,1);
    mainLayout->addWidget(editDistance,5,2);
    mainLayout->addWidget(new QLabel("Координаты"),6,1);
    mainLayout->addWidget(editCoordinate,6,2);


    QPushButton* btnOk = new QPushButton("&ОК");

     mainLayout->addWidget(btnOk,7,1,1,2);

    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Информация о звезде");


    //Располагаем диалог над основным окном
    int gx = 100;
    int gy = 100;
    if (pwgt!=nullptr)
    {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();

    }
    this->setGeometry(gx+10,gy+10,300,150);
}

QString EditStarDialog::id() const
{
    return editID->text();
}
QString EditStarDialog::name() const
{
    return editName->text();
}
QString EditStarDialog::pleiad() const
{
    return editPleiad->text();//currentText для комбобокса
}
QString EditStarDialog::size() const
{
    return editSize->text();
}
QString EditStarDialog::distance() const
{
    return editDistance->text();
}
QString EditStarDialog::coordinate() const
{
    return editCoordinate->text();
}

void EditStarDialog::SetUpDialog(QString id, QString name,QString pleiad,QString size,QString distance,QString coordinate)
{
    editID->setText(id);
    editName->setText(name);
    editPleiad->setText(pleiad);
    editSize->setText(size);
    editDistance->setText(distance);
    editCoordinate->setText(coordinate);

//    int ind = editFaculty->findText(faculty);//для комбобокса
//    if (ind>=0)
//    {
//        editFaculty->setCurrentIndex(ind);
//    }
}
