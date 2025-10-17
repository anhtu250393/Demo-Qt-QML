#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "source/data.h"
#include "source/listmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    Data myData;
    myData.setMessage("Hello from C++!");
    engine.rootContext()->setContextProperty("applicationData", &myData);

    listModel modelData;
    engine.rootContext()->setContextProperty("listModel", &modelData);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("DemoChatApp", "Main");

    return app.exec();
}
