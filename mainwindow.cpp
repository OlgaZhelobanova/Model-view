#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"
#include "model.h"
#include "QGridLayout"
#include "editstardialog.h"
#include "dialogdelegate.h"
#include "linedelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tableView = new QTableView();
    myModel = new MyModel(this);
    tableView->setModel( myModel );

      DialogDelegate* ddel = new DialogDelegate(nullptr,this);
      lineDelegate* ldel = new lineDelegate();

      tableView->setItemDelegateForColumn(0,ddel);
      tableView->setItemDelegateForColumn(1,ldel);
      tableView->viewport()->setAttribute(Qt::WA_Hover);//чтобы делегаты работали


    QGridLayout* glay= new QGridLayout();
    glay->addWidget(tableView,1,1,1,2);

    QPushButton* pb1 = new QPushButton("Add row");
    QPushButton* pb2 = new QPushButton("Delete row");

    glay->addWidget(pb1,2,1);
    glay->addWidget(pb2,2,2);

    QObject::connect(pb1,SIGNAL(clicked(bool)),this,SLOT(AddRow()));//слоты-сигналы
    QObject::connect(pb2,SIGNAL(clicked(bool)),this,SLOT(DeleteRow()));


    QWidget* wdg=new QWidget();
    wdg->setLayout(glay);

    this->setCentralWidget(wdg);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddRow()
{
    EditStarDialog* addDialog = new EditStarDialog(this);
    if (addDialog->exec() == QDialog::Accepted)
    {
        Star* str = new Star(addDialog->id(),addDialog->name(),addDialog->pleiad(),
                              addDialog->size(), addDialog->distance(), addDialog->coordinate(), this);
        myModel->AddStar(str);
    }

    addDialog->deleteLater();
}

void MainWindow::DeleteRow()
{
    QModelIndex selList = tableView->currentIndex();
    myModel->DeleteStar(selList.row());
}


