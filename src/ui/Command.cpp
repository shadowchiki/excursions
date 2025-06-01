#include "Command.hpp"

namespace ui
{

Command::Command(std::string tittle)
    : mTittle(tittle)
{
}

std::string Command::getTittle()
{
    return mTittle;
}

}  // namespace ui
