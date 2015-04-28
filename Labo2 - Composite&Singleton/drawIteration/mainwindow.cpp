#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->resize(1200,800);
    setWindowTitle("Fractal - DISPLAY Mode");

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

    aboutAct = new QAction(tr("&About"),this);
    connect(aboutAct,SIGNAL(triggered()),this, SLOT(about()));

    quitAction = new QAction(tr("&Quit"),this);
    quitAction->setShortcut(QKeySequence::Quit);
    connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));
    this->addAction(quitAction);


    mainMenu = new QMenu("MainMenu",this);
    mainMenu->addAction(displayWidget->getSwitchToEditionOrDisplay());
    mainMenu->addAction(helpAction);
    mainMenu->addAction(quitFullScreen);
    mainMenu->addSeparator();
    mainMenu->addAction(aboutAct);
    mainMenu->addSeparator();
    mainMenu->addAction(quitAction);

    this->menuBar()->addMenu(mainMenu);


    helpText = new QString();
    helpText->append("Shortcuts\t\t|  Effects\n------------------------------------------------------------------------------\n- ctrl+m\t\t  switch to Edition mode or return to Display mode\n- esc\t\t\t  leave fullscreen mode\n\n\nMouse actions \t|  Effects\n------------------------------------------------------------------------------\n- double click\t\t  switch to fullscreen mode or leave it\n- middleButton click \t  restore original zoom\n- wheel \t\t  zoom\n- rightButton+drag \t  rotate conterclockwise\n- leftButton+drag\n   a) Edition mode\t  draw 1st fractal line (max 5 fractals)\n   b) Display Mode\t  move around fractals");

    updateZoom(1);

    connect(displayWidget, SIGNAL(scaleFactorChanged(double)), this, SLOT(updateZoom(double)));
    connect(displayWidget, SIGNAL(zoomLimitReached(bool)), this, SLOT(zoomLimitReached(bool)));
    connect(displayWidget, SIGNAL(switchMode(bool)),this,SLOT(switchMode(bool)));
}

MainWindow::~MainWindow()
{
    delete(helpText);
}

void MainWindow::help()
{
    QMessageBox::information(this,tr("Help using this app"), *helpText);
}

void MainWindow::about()
{
    QMessageBox::about(this,"About this project","Design Pattern - EQUIPE I :\n -Bandelier Matthieu\n -Gonin Nicolas \n -Luy Karim\n\nLABO 2 - Singleton/Composite");
}

void MainWindow::updateZoom(double zoom)
{
    statusBar()->showMessage(QString("Zoom : x%1").arg(QString::number(zoom,'f',2)));
}

void MainWindow::zoomLimitReached(bool isMaxReached)
{
    QMessageBox::warning(this,"! Zoom limit !", isMaxReached?"Max zoom reached":"Min zoom reached");
}

void MainWindow::switchMode(bool toEditionMode)
{
    QString title = QString("Fractal - ");
    setWindowTitle(title.append(toEditionMode?"EDITION Mode":"DISPLAY Mode"));
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent * event)
{
    if ( event->button() == Qt::LeftButton )
    {
        if(isFullScreen()){
            showNormal();
        }
        else{
            showFullScreen();
        }
    }
}
