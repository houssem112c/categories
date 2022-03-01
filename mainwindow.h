#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include "categories.h"
#include "ui_mainwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_17_clicked();








private:
    Ui::MainWindow *ui;
    categories tmpcategories;

};
#endif // MAINWINDOW_H
