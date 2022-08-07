#include "pointslistmodel.h"
#include <QDebug>
#include <QPointF>

PointsListModel::PointsListModel(QObject *parent)
    : QAbstractListModel(parent)
    , _pointsList{}
{}

void PointsListModel::addPoint(QPointF* point)
{
    int index = _pointsList.size();
    beginInsertRows(QModelIndex(), index, index);
    _pointsList.append(point);
    endInsertRows();
}

int PointsListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _pointsList.size();
}

QVariant PointsListModel::data(const QModelIndex &index, int role) const
{
    auto const row = index.row();

    switch (role) {
    case static_cast<int>(Roles::xRole):
        return _pointsList.at(row)->x();
    case static_cast<int>(Roles::yRole):
        return _pointsList.at(row)->y();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> PointsListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[static_cast<int>(Roles::xRole)] = "xRole";
    roles[static_cast<int>(Roles::yRole)] = "yRole";
    return roles;
}

void PointsListModel::resetModel()
{
    qDebug() << pointsList().size();
    beginRemoveRows(QModelIndex(),0,rowCount(QModelIndex()) - 1);
    _pointsList.clear();
    endRemoveRows();
    qDebug() << _pointsList.size();
}

QList<QPointF*> PointsListModel::pointsList() const
{
    return _pointsList;
}

QPointF* PointsListModel::pointAt(int index) const
{
    return _pointsList.at(index);
}
