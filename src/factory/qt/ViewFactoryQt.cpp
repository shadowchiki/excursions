#include "ViewFactoryQt.hpp"
#include <ui/qt/QtView.hpp>

namespace factory::qt
{

std::shared_ptr<ui::View> ViewFactoryQt::view()
{
    if (not mView)
    {
        mView = std::make_shared<ui::qt::QtView>();
    }
    return mView;
}

}  // namespace factory::console
