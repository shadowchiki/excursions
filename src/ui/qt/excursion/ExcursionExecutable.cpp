#include "ExcursionExecutable.hpp"

namespace ui::qt::excursion
{

ExcursionExecutable::ExcursionExecutable(QObject* parent)
    : QObject(parent)
    , mNames()
    , controller()
{
}

QStringList ExcursionExecutable::findExcursions(QString startDate, QString endDate)
{
    mNames.clear();
    auto excursions = controller.getByDates(startDate.toStdString(), endDate.toStdString());

    for (auto excursion : excursions)
    {
        mNames.push_back(QString::fromStdString(excursion->getDescription()));
    }

    return mNames;
}

}  // namespace ui::qt::excursion
