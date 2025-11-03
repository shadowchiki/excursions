#include "ExcursionEntity.hpp"

namespace ui::qt::excursion {

ExcursionEntity::ExcursionEntity(QObject *parent) : QObject(parent), mId() {}

QString ExcursionEntity::id() const { return mId; }
QString ExcursionEntity::description() const { return mDescription; }
QString ExcursionEntity::date() const { return mDate; }
double ExcursionEntity::price() const { return mPrice; }
int ExcursionEntity::durationDays() const { return mDurationDays; }

void ExcursionEntity::setId(QString id) {
  if (id != mId) {
    mId = id;
    emit onIdChange(mId);
  }
}

void ExcursionEntity::setDescription(QString description) {

  if (description != mDescription) {
    mDescription = description;
    emit onDescriptionChange(mDescription);
  }
}
void ExcursionEntity::setDate(QString date) {
  if (date != mDate) {
    mDate = date;
    emit onDateChange(mDate);
  }
}
void ExcursionEntity::setPrice(double price) {
  if (price != mPrice) {
    mPrice = price;
    emit onPriceChange(mPrice);
  }
}
void ExcursionEntity::setDurationDays(int durationDays) {
  if (durationDays != mDurationDays) {
    mDurationDays = durationDays;
    emit onDurationDaysChange(mDurationDays);
  }
}
} // namespace ui::qt::excursion
