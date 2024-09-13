#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <OpenGLItem.hpp>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<OpenGLItem>("TwoD.Sandbox", 1, 0, "OpenGLItem");

    const QUrl url(u"qrc:/TwoD-Sandbox/source_gui/Main.qml"_qs);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
