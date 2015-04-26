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

    quitFullScreen = new QAction(tr("&Leave FullScreen"),this);
    quitFullScreen->setShortcut(Qt::Key_Escape);
    connect(quitFullScreen,SIGNAL(triggered()),this,SLOT(showNormal()));
    this->addAction(quitFullScreen);

    quitAction = new QAction(tr("&Quit"),this);
    quitAction->setShortcut(QKeySequence::Quit);
    connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));
    this->addAction(quitAction);


    mainMenu = new QMenu("MainMenu",this);
    mainMenu->addAction(helpAction);
    mainMenu->addAction(quitFullScreen);
    mainMenu->addSeparator();
    mainMenu->addAction(quitAction);

    this->menuBar()->addMenu(mainMenu);


    helpText = new QString();
    helpText->append("- Ctrl+m \t : swap to edit mode or return to display mode \n- Double click\t : swap to fullscreen mode (escape to leave)\n- Wheel \t\t : zoom\n- RightButton+drag \t: Rotate conterclockwise\n- MiddleButton Click \t: Restore original zoom\n- LeftButton+drag\n\tEdition mode\t: Draw start line\n\tDisplay Mode\t: Move");

    updateZoom(1);

    connect(displayWidget, SIGNAL(scaleFactorChanged(double)), this, SLOT(updateZoom(double)));
}

void MainWindow::help()
{
    QMessageBox::information(this,tr("Help using this app"), *helpText);
}

void MainWindow::updateZoom(double zoom)
{
    statusBar()->showMessage(QString("Zoom : x%1").arg(QString::number(zoom,'f',2)));
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent * event)
{
    if ( event->button() == Qt::LeftButton )
    {
        showFullScreen();
    }
}
