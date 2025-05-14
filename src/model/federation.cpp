#include "federation.h"

Federation::Federation(std::string id, std::string name)
    : mId(id)
    , mName(name)
{
}

std::string Federation::getId()
{
    return mId;
}

std::string Federation::getName()
{
    return mName;
}
