#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widget.h"
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

public slots:
    void help();
    void about();
    void updateZoom(double);
    void zoomLimitReached(bool isMaxReached);
    void switchMode(bool toEditionMode);

private:
    Widget *displayWidget;
    QAction *helpAction;
    QAction *aboutAct;
    QAction *quitAction;
    QAction *quitFullScreen;


    QMenu* mainMenu;

    QString* helpText;

protected:
    void mouseDoubleClickEvent(QMouseEvent *);


};

#endif // MAINWINDOW_H
