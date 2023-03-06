#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QAbstractListModel>
#include <QQuickItem>
#include <memory>


#include <QDebug>


class ToolBarModel;

class ToolBarItem : public QQuickItem
{
    Q_OBJECT
public:
    ToolBarItem();

    Q_INVOKABLE int counter() const { return 5;}



Q_SIGNALS:
    void modelChanged();

private:




};






#endif // TOOLBAR_H
