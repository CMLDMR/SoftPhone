#ifndef GLOBAL_GENERATOR_H
#define GLOBAL_GENERATOR_H

#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>

#include "QML/keyboarditem.h"
#include "QML/toolbar.h"

namespace Global {

class Generator : public QObject
{
    Q_OBJECT

private:
    explicit Generator(QObject *parent = nullptr);
    virtual ~Generator(){}
    static Generator *mInstance;

public:
    static Generator* createSingletonInstance( QQmlEngine* engine,QJSEngine* scriptEngine );


    Q_INVOKABLE KeyBoardItem* getKeyBoardModel();


signals:


private:
    std::unique_ptr<KeyBoardItem> mKeyboardModel = nullptr;


};

} // namespace Global

#endif // GLOBAL_GENERATOR_H
