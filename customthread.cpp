#include "customthread.h"
#include <QDebug>
#include <QMutex>
#include <QWaitCondition>
#include <QRandomGenerator>

CustomThread::CustomThread(
        bool& started,
        QObject* parent)
    : QThread(parent)
    , _started(started)
    , _pause(false)
    , _sync(new QMutex)
    , _waitForPlay(new QWaitCondition)
    , _generator(new QRandomGenerator)
{}

CustomThread::~CustomThread()
{
    quit();
    requestInterruption();
    wait();
}

void CustomThread::resume()
{
    _sync->lock();
    _pause = false;
    _sync->unlock();
    _waitForPlay->wakeAll();
}

void CustomThread::pause()
{
    _sync->lock();
    _pause = true;
    _sync->unlock();
}

void CustomThread::run()
{
    while(_started){
        _sync->lock();
        if(_pause)
            _waitForPlay->wait(_sync);
        _sync->unlock();

        emit pointGenerated(_generator->generateDouble(),_generator->generateDouble());
        sleep(1);
    }
}
