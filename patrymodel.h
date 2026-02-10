#ifndef PATRYMODEL_H
#define PATRYMODEL_H

#include <QObject>
#include <QAbstractListModel>

struct model{
    QString partyname;
    QString symbol;
    qint64 count;
};

class PatryModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PatryModel(QObject *parent = nullptr);
    enum Roles{
        PartyNameRole = Qt::UserRole+1,
        SymboleRole,
        CountRole
    };
    int rowCount(const QModelIndex &parent= QModelIndex())const override;
    QVariant data(const QModelIndex &index,int role)const override;
    QHash<int,QByteArray> roleNames()const override;
    void addParty(QString name,QString symbol="");
    Q_INVOKABLE void vote(int index);

signals:

private:
    QList<model> m_model;
};

#endif // PATRYMODEL_H
