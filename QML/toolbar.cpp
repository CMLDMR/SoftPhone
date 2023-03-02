#include "toolbar.h"

ToolBar::ToolBar(QObject *parent)
    : QAbstractListModel{parent}
{

}


int ToolBar::rowCount(const QModelIndex &parent) const
{
    return 0;
}

QVariant ToolBar::data(const QModelIndex &index, int role) const
{
    return QVariant{};
}
