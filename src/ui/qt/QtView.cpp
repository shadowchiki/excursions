#include "QtView.hpp"
#include <qqml.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <excursion/ExcursionExecutable.hpp>

namespace ui::qt
{

Execution QtView::init(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    // qmlRegisterType<excursion::ExcursionExecutable>(
    //     "ExcursionExecutable", 1, 0, "ExcursionExecutable");
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
