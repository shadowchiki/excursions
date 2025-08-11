#pragma once
#include <controller/ExcursionController.h>
#include <qqmlintegration.h>
#include <QList>
#include <QObject>
#include <QQuickItem>
#include <QStringListModel>

namespace ui::qt::excursion
{
class ExcursionExecutable : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    ExcursionExecutable(QObject* parent = nullptr);
    virtual ~ExcursionExecutable() = default;

public slots:
    QStringList findExcursions(QString startDate, QString endDate);

private:
    QStringList mNames;
    controller::excursion::ExcursionController controller;
};
}  // namespace ui::qt::excursion
