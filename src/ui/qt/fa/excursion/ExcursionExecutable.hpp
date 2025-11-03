#pragma once
#include "ExcursionEntity.hpp"
#include <controller/ExcursionController.h>
#include <qlist.h>
#include <qqmlintegration.h>
#include <QList>
#include <QObject>
#include <QQuickItem>
#include <QStringListModel>
#include <qqmllist.h>

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
    QQmlListProperty<ExcursionEntity> findExcursions(QString startDate, QString endDate);

private:
    QList<ExcursionEntity*> mExcursions;
    controller::excursion::ExcursionController controller;
};
}  // namespace ui::qt::excursion
