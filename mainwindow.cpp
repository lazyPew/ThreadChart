#include "mainwindow.h"

#include <QPushButton>
#include <QDebug>

#include "chartview.h"
#include "customthread.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , _chartView{new ChartView()}
    , _thread(new CustomThread(_started,this))
    , _playButton(new QPushButton(QIcon(":/play60"),"",this))
    , _pauseButton(new QPushButton(QIcon(":/pause60"),"",this))
    , _stopButton(new QPushButton(QIcon(":/stop60"),"",this))
{

    resize(800,600);
    auto layout = new QGridLayout;
    layout->addWidget(_chartView,0,0,1,5);
    {
        int i = 0;
        for (auto button : {_playButton, _pauseButton, _stopButton}) {
            if (i>0)
                button->setEnabled(false);
            button->setMinimumSize(50,50);
            button->setMaximumSize(100,100);
            layout->addWidget(button,1,i,1,1);
            i+=2;
        }
    }

    setLayout(layout);

    connect(_playButton, &QPushButton::clicked, this, &MainWindow::play);
    connect(_pauseButton, &QPushButton::clicked, this,&MainWindow::pause);
    connect(_stopButton, &QPushButton::clicked, this,&MainWindow::stop);

    connect(_chartView, &ChartView::addedPoint,_thread, &CustomThread::resume);
    connect(_thread, &CustomThread::valueGenerated,[this](double xVal, double yVal){
        _chartView->addPoint(xVal,yVal);
    });
}

void MainWindow::play()
{
    _started = true;
    if(_thread->isRunning()){
        _thread->resume();
    }
    else{
        _thread->start();
    }
    _playButton->setEnabled(false);
    _pauseButton->setEnabled(true);
    _stopButton->setEnabled(true);
}

void MainWindow::pause()
{
    _thread->pause();
    _playButton->setEnabled(true);
    _pauseButton->setEnabled(false);
    _stopButton->setEnabled(true);
}

void MainWindow::stop()
{
    _started = false;
    _chartView->clearPoints();
    _playButton->setEnabled(true);
    _pauseButton->setEnabled(false);
    _stopButton->setEnabled(false);
}

