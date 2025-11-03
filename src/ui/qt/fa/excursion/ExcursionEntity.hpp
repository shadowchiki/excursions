#pragma once
#include <QList>
#include <QObject>
#include <QQuickItem>
#include <QStringListModel>
#include <controller/ExcursionController.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>

namespace ui::qt::excursion {

class ExcursionEntity : public QObject {

  Q_OBJECT
  QML_ELEMENT

  Q_PROPERTY(QString id READ id NOTIFY onIdChange)
  Q_PROPERTY(QString description READ  description NOTIFY onDescriptionChange)
  Q_PROPERTY(QString date READ date NOTIFY onDateChange)
  Q_PROPERTY(double price READ price NOTIFY onPriceChange)
  Q_PROPERTY(int durationDays READ durationDays NOTIFY onDurationDaysChange)

public:
  ExcursionEntity(QObject *parent = nullptr);
  virtual ~ExcursionEntity() = default;

  void setId(QString id);
  void setDescription(QString description);
  void setDate(QString date);
  void setPrice(double price);
  void setDurationDays(int durationDays);

  QString id() const;
  QString description() const;
  QString date() const;
  double price() const;
  int durationDays() const;

signals:
  void onIdChange(QString id);
  void onDescriptionChange(QString description);
  void onDateChange(QString date);
  void onPriceChange(double price);
  void onDurationDaysChange(int durationDays);

private:
  QString mId;
  QString mDescription;
  QString mDate;
  double mPrice;
  int mDurationDays;
};

} // namespace ui::qt::excursion
