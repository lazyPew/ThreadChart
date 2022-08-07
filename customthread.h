#ifndef CUSTOMTHREAD_H
#define CUSTOMTHREAD_H

#include <QThread>

class QWaitCondition;
class QMutex;
class QRandomGenerator;

class CustomThread : public QThread
{
    Q_OBJECT
public:
    CustomThread(
            bool& started,
            QObject *parent = nullptr);
    ~CustomThread();
    void resume();
    void pause();

signals:
    void valueGenerated(double xVal, double yVal);

protected:
    void run() override;
    void generateRandomPoint();

private:
    bool& _started;
    bool _pause;

    QMutex* _sync;
    QWaitCondition* _waitForPlay;
    QRandomGenerator* _generator;
};

#endif // CUSTOMTHREAD_H
