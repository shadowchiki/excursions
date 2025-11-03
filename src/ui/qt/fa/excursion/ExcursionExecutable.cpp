#include "ExcursionExecutable.hpp"
#include "ExcursionEntity.hpp"

#include <qcontainerfwd.h>
#include <qqmllist.h>

namespace ui::qt::excursion {

ExcursionExecutable::ExcursionExecutable(QObject *parent)
    : QObject(parent), mExcursions(), controller() {}

QQmlListProperty<ExcursionEntity>
ExcursionExecutable::findExcursions(QString startDate, QString endDate) {
  auto excursions =
      controller.getByDates(startDate.toStdString(), endDate.toStdString());
  mExcursions.clear();

  for (auto excursion : excursions) {
    auto excursionPtr = new ExcursionEntity(this);
    excursionPtr->setDescription(QString::fromStdString(excursion->getDescription()));
    excursionPtr->setId(QString::fromStdString(excursion->getId()));
    excursionPtr->setDate(QString::fromStdString(excursion->getDate()));
    excursionPtr->setDurationDays(excursion->getDurationDays());
    excursionPtr->setPrice(excursion->getPrice());
    mExcursions.push_back(excursionPtr);
  }

  return QQmlListProperty<ExcursionEntity>(this, &mExcursions);
}

} // namespace ui::qt::excursion
