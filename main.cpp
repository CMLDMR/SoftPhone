#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "mainwindow.h"
#include "QML/keyboarditem.h"
#include "generator.h"

#include <QApplication>

#include <QSoundEffect>

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.addImportPath("qrc:/QML");


    qmlRegisterType<KeyBoardItem>("com.softphone.keyboard",1,0, "KeyBoard");
    qmlRegisterSingletonType<Global::Generator>("com.softphone.global", 1 , 0 , "Global" , Global::Generator::createSingletonInstance );

    const QUrl url(u"qrc:/SoftPhone/main.qml"_qs);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();

}
