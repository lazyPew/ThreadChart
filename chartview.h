#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QWidget>
#include <QtCharts/QtCharts>

class ChartView : public QChartView
{
    Q_OBJECT
public:
    explicit ChartView(QWidget *parent = 0);

public slots:
    void addPoint(double,double);
    void clearPoints();

signals:
    void addedPoint();

private:
    QScatterSeries* _series;
};
#endif // CHARTVIEW_H
