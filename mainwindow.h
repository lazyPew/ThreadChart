#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class ChartView;
class QPushButton;
class CustomThread;
class QRandomGenerator;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

protected:
    void play();
    void pause();
    void stop();

private:
    ChartView* _chartView;
    bool _started = false;
    bool _paused;
    CustomThread* _thread;

    QRandomGenerator* _rgen;
    QPushButton* _playButton;
    QPushButton* _pauseButton;
    QPushButton* _stopButton;
};
#endif // MAINWINDOW_H
