#include "keyboarditem.h"


#include <QDebug>


KeyBoardItem::KeyBoardItem(QObject *parent)
    :QAbstractListModel{parent}
{

    beginResetModel();
    mList.push_back("1");
    mList.push_back("2");
    mList.push_back("3");
    mList.push_back("4");
    mList.push_back("5");
    mList.push_back("6");
    mList.push_back("7");
    mList.push_back("8");
    mList.push_back("9");
    mList.push_back("*");
    mList.push_back("0");
    mList.push_back("#");
    endResetModel();

}


int KeyBoardItem::rowCount(const QModelIndex &parent) const
{
    return mList.size();
}

QVariant KeyBoardItem::data(const QModelIndex &index, int role) const
{

    if( index.isValid() ){
        switch (role) {
        case keyBoardName:
            return QVariant{mList[index.row()].c_str()};
            break;
        default:
            break;
        }

    }

    return QVariant{};
}


QHash<int, QByteArray> KeyBoardItem::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[keyBoardName] = "keyboardName";
    return roles;
}
