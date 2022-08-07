#ifndef DOTSLISTMODEL_H
#define DOTSLISTMODEL_H

#include <QAbstractListModel>

//struct Dot{
//    double xCoord;
//    double yCoord;
//};

class PointsListModel : public QAbstractListModel
{
public:
    explicit PointsListModel(QObject *parent = nullptr);

    enum Roles{
        xRole = Qt::UserRole + 1,
        yRole
    };

    void addPoint(QPointF*);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    void resetModel();

public slots:
    QList<QPointF*> pointsList() const;
    QPointF* pointAt(int index) const;

private:
    QList<QPointF*> _pointsList;
};

#endif // DOTSLISTMODEL_H
