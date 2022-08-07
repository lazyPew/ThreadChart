#include "chartview.h"

ChartView::ChartView(//QList<QPointF*> pointsList,
                     QWidget *parent)
    : QChartView(new QChart(), parent)
    , _series{new QScatterSeries()}
{
    setRenderHint(QPainter::Antialiasing);

    chart()->addSeries(_series);;
    chart()->createDefaultAxes();
    chart()->axes(Qt::Vertical).first()->setMax(1);
    chart()->axes(Qt::Horizontal).first()->setMax(1);
}

void ChartView::addPoint(double xNew, double yNew)
{
    QPointF point = QPointF(xNew,yNew);
    *_series << point;
    emit addedPoint();
}

void ChartView::clearPoints()
{
    _series->clear();
}


