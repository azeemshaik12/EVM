#include "patrymodel.h"
#include <QDebug>

PatryModel::PatryModel(QObject *parent)
    : QAbstractListModel{parent}
{
    addParty("AAP","qrc:/images/AAP.png");
    addParty("AIADMK","qrc:/images/AIADMK.png");
    addParty("BJP","qrc:/images/BJP.png");
    addParty("BSP","qrc:/images/BSP.png");
    addParty("CPI","qrc:/images/CPI.png");
    addParty("INC","qrc:/images/INC.png");
    addParty("RJD","qrc:/images/RJD.png");
    addParty("SP","qrc:/images/SP.png");
    addParty("TMC","qrc:/images/TMC.png");
    addParty("NOTA","qrc:/images/NOTA.png");
}

int PatryModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_model.count();
}

QVariant PatryModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || index.row()>=m_model.size())
        return QVariant();
    const model &dummy = m_model[index.row()];
    switch(role){
    case PartyNameRole:
        return dummy.partyname;
    case SymboleRole:
        return dummy.symbol;
    case CountRole:
        return dummy.count;
    default:
       return QVariant();
    }

}

QHash<int, QByteArray> PatryModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[PartyNameRole] = "partyname";
    roles[SymboleRole] = "symbol";
    roles[CountRole] = "count";
    return roles;
}

void PatryModel::addParty(QString name, QString symbol)
{
    beginInsertRows(QModelIndex(),m_model.size(),m_model.size());
    m_model.append({name,symbol,0});
    endInsertRows();
}

void PatryModel::vote(int index)
{
    m_model[index].count++;
    qDebug()<<"party:"<<m_model[index].partyname<<",Votes:"<<m_model[index].count;

}

