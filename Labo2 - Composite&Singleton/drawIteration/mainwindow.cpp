#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->resize(800,600);
    setWindowTitle("DP - EQUIPE I - LABO 2 / Fractal ");

    displayWidget = new Widget(this);
    this->setCentralWidget(displayWidget);

    helpAction = new QAction( tr("&Help..."), this);
    helpAction->setShortcut(tr("Ctrl+H"));
    helpAction->setStatusTip(tr("Get help"));
    connect(helpAction, SIGNAL(triggered()), this, SLOT(help()));

    helpMenu = new QMenu("Help",this);
    helpMenu->addAction(helpAction);

    this->menuBar()->addMenu(helpMenu);


    quitFullScreen = new QAction(this);
    quitFullScreen->setShortcut(Qt::Key_Escape);
    connect(quitFullScreen,SIGNAL(triggered()),this,SLOT(showNormal()));
    this->addAction(quitFullScreen);
}

void MainWindow::help()
{
    QMessageBox::information(this,"Help using this app",
                             "Ctrl+m \t\t : swap to edit mode or return to display mode \nDouble click\t : swap to fullscreen mode (escape to leave)\nWheel \t\t : zoom\n\nEdition Mode :\n\tDraw line \t: LeftButton+drag\n\nDisplay Mode :\n\tMove \t : LeftButton+drag\n\tRotate \t : RightButton+drag\n\tRestore Original Zoom : MiddleButtonClick");
}
