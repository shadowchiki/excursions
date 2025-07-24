#include "ExcursionExecutable.hpp"

namespace ui::qt::excursion
{

ExcursionExecutable::ExcursionExecutable(QQuickItem* parent)
    : QQuickItem(parent)
    , mTittle()
{
}

QString ExcursionExecutable::tittle()
{
    return mTittle;
}

void ExcursionExecutable::setTittle(QString& tittle)
{
    if (tittle != mTittle)
    {
        mTittle = tittle;
        emit tittleChange();
    }
}

QList<QString> ExcursionExecutable::findExcursions()
{
    QList<QString> names;
    names.push_back("Excursion1");
    names.push_back("Excursion2");
    names.push_back("Excursion3");
    names.push_back("Excursion4");
    names.push_back("Excursion5");
    return names;
}

}  // namespace ui::qt::excursion
