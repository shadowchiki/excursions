#include "childrenpartner.h"

ChildrenPartner::ChildrenPartner(std::string id, std::string name, std::shared_ptr<Partner> parent)
    : Partner(id, name)
    , parent(parent)
{
}

int ChildrenPartner::discount()
{
}
