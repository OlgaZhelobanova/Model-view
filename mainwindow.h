#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"
#include "QTableView"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void AddRow();//добавить строку
    void DeleteRow();//удалить строку

private:
    Ui::MainWindow *ui;
    MyModel* myModel;
    QTableView* tableView;
};
#endif // MAINWINDOW_H










