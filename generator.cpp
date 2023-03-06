#include "generator.h"

namespace Global {


Generator* Generator::mInstance = nullptr;


Generator::Generator(QObject *parent)
    : QObject{parent}
{

}

Generator *Generator::createSingletonInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    if(mInstance==nullptr){ mInstance = new Generator;}
    return mInstance;
}

KeyBoardItem *Generator::getKeyBoardModel()
{
    if( !mKeyboardModel ){
        mKeyboardModel = std::make_unique<KeyBoardItem>();
    }
    return mKeyboardModel.get();
}


} // namespace Global
