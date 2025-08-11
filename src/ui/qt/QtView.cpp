#include "QtView.hpp"
#include <qqml.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

namespace ui::qt
{

Execution QtView::init(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath(QString("%1/excursion").arg(QGuiApplication::applicationDirPath()));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("main", "Main");

    app.exec();
    return Execution::CONTINUE;
}

}  // namespace ui::qt
