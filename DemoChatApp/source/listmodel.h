#ifndef LISTMODEL_H
#define LISTMODEL_H

 #include <QAbstractListModel>
#include <QList>
#include <QString>

class listModel : public QAbstractListModel
{
    Q_OBJECT
public:
    struct ListItem {
        QString name;
        int number;
    };

    enum Roles {
        NameRole = Qt::UserRole + 1,
        NumberRole
    };

    explicit listModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addItem(const QString& name, const int& number);

private:
    QList<ListItem> m_data;

signals:
};

#endif // LISTMODEL_H
