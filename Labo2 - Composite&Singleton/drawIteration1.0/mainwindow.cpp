#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->resize(1200,800);
    setWindowTitle("Fractal - Mode : DISPLAY");

    int detailLevel = 5;
    displayWidget = new Widget(detailLevel, this);
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

    modeAction = new QAction(tr("Edit"),this);
    modeAction->setShortcut(tr("Ctrl+M"));
    connect(modeAction, SIGNAL(triggered()), displayWidget, SLOT(changeMode()));
    connect(displayWidget, SIGNAL(switchMode(bool)),this,SLOT(switchMode(bool)));


    mainMenu = new QMenu("MainMenu",this);
    mainMenu->addAction(modeAction);
    mainMenu->addAction(helpAction);
    mainMenu->addAction(quitFullScreen);
    mainMenu->addSeparator();
    mainMenu->addAction(aboutAct);
    mainMenu->addSeparator();
    mainMenu->addAction(quitAction);

    this->menuBar()->addMenu(mainMenu);


    helpText = new QString();
    helpText->append("Shortcuts\t\t|  Effects\n------------------------------------------------------------------------------\n- ctrl+m\t\t  switch to Edition mode or return to Explore mode\n- esc\t\t\t  leave full screen\n\n\nMouse actions \t|  Effects\n------------------------------------------------------------------------------\n- left double click\t  switch to full screen or leave it\n- middle click \t\t  restore original zoom\n- wheel \t\t  zoom\n- right click+drag \t  rotate conterclockwise\n- left click+drag\n   a) Edition mode\t  draw 1st fractal line (max 3 fractals)\n   b) Explore Mode\t  move around fractals");

    updateZoom(1);

    connect(displayWidget, SIGNAL(scaleFactorChanged(double)), this, SLOT(updateZoom(double)));
    connect(displayWidget, SIGNAL(zoomLimitReached(bool)), this, SLOT(zoomLimitReached(bool)));

    int max = 10;
    int min = 1;

    slider = new QSlider(Qt::Horizontal, this);
    slider->setRange(min,max);
    slider->setToolTip("Fractal(s) deepness");
    slider->setValue(detailLevel);
    slider->setStatusTip("Fractal(s) deepness");
    slider->move(5,75);

    slider->setTickInterval(1);
    slider->setTickPosition(QSlider::TicksLeft);
    slider->setSingleStep(1);
    slider->setPageStep(2);
    slider->setMaximumWidth(150);

    labelSlider = new QLabel("Detail level :",this);
    labelSlider->move(10,45);
    labelSlider->setMargin(12);

    labelSliderCount = new QLabel(QString::number(detailLevel),this);
    labelSliderCount->move(10,60);
    labelSliderCount->resize(40,10);
    labelSliderCount->setMargin(5);

    connect(slider,SIGNAL(valueChanged(int)),labelSliderCount,SLOT(setNum(int)));
    connect(slider,SIGNAL(valueChanged(int)),displayWidget,SLOT(redraw(int)));



    toolBar = addToolBar(tr("Deepness"));
    toolBar->addAction(modeAction);
    toolBar->addSeparator();
    toolBar->addWidget(labelSlider);
    toolBar->addWidget(slider);
    toolBar->addWidget(labelSliderCount);



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
    QString title = QString("Fractal - Mode : ");
    QString actionText;

    if (toEditionMode)
    {
        title.append("EDITION");
        actionText = "Explore";
        slider->setDisabled(true);
        labelSlider->setDisabled(true);
        labelSliderCount->setDisabled(true);
    }
    else
    {
        title.append("EXPLORER");
        actionText = "Edit";
        slider->setDisabled(false);
        labelSlider->setDisabled(false);
        labelSliderCount->setDisabled(false);
    }
    setWindowTitle(title);
    modeAction->setText(actionText);
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
