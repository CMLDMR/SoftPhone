#include "keyboarditem.h"

#include <QFile>
#include <QByteArray>

#include <QDebug>


KeyBoardItem::KeyBoardItem(QObject *parent)
    :QAbstractListModel{parent}
{

    QStringList fileList;
    for( int i = 0 ; i < 10 ; i++ ){
        fileList.append(QString("Dtmf-%1.wav").arg(i));
    }
    fileList.append("Dtmf-pound.wav");
    fileList.append("Dtmf-star.wav");
    fileList.append("incoming.wav");
    fileList.append("incoming.wav");
    fileList.append("outgoing.wav");
    fileList.append("ring.wav");

    for( const auto &fileName : fileList ){
        auto filePath = ":/sounds/"+fileName;
        QFile file(filePath);
        if( file.open(QIODevice::ReadOnly) ){
            auto ar = file.readAll();
            QFile write(fileName);
            if( write.open(QIODevice::ReadWrite) ){
                write.write(ar);
                write.close();
            }
            file.close();
        }
    }

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

void KeyBoardItem::playSound(const QString &value)
{
    QString tone = value;
    if( tone == "*" ){
        tone = "star";
    }
    if( tone == "#" ){
        tone = "pound";
    }
    mPLay.setSource(QUrl::fromLocalFile(QString("Dtmf-%1.wav").arg(tone)));
    mPLay.setLoopCount(1);
    mPLay.setVolume(1.00f);
    mPLay.play();

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
