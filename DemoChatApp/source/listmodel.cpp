#include "listmodel.h"

 #include <QDebug>

listModel::listModel(QObject *parent) : QAbstractListModel{parent}
{
    m_data << ListItem{"Alice", 30} << ListItem{"Bob", 25} << ListItem{"Charlie", 35};
}

int listModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.size();
}

QVariant listModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_data.size())
        return QVariant();

    const ListItem &item = m_data.at(index.row());
    switch (role) {
    case NameRole:
        return item.name;
    case NumberRole:
        return item.number;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> listModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[NumberRole] = "number";
    return roles;
}

void listModel::addItem(const QString& name, const int& number) {
    qDebug() << "Mname:" << name;
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_data.append({name, number});
    endInsertRows();
}
