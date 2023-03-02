#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QAbstractListModel>

class ToolBar : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ToolBar(QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
};

#endif // TOOLBAR_H
