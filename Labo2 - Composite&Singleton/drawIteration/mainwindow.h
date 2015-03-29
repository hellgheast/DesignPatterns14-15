#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widget.h"
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

signals:

public slots:
    void help();

private:
    Widget* displayWidget;
    QAction* helpAction;
    QMenu* helpMenu;
    QAction* quitFullScreen;


};

#endif // MAINWINDOW_H
