#ifndef KEYBOARDITEM_H
#define KEYBOARDITEM_H

#include <QAbstractListModel>
#include <vector>
#include <QSoundEffect>

class KeyBoardItem : public QAbstractListModel
{
    Q_OBJECT
public:
    KeyBoardItem(QObject* parent = nullptr);

    enum PersonelModelRoles{
        keyBoardName = Qt::UserRole+1,

    };

    Q_INVOKABLE void playSound(const QString &value);

signals:


private:
    std::vector<std::string> mList;

    QSoundEffect mPLay;


    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;

    // QAbstractItemModel interface
public:
    virtual QHash<int, QByteArray> roleNames() const override;
};

#endif // KEYBOARDITEM_H
