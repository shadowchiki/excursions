#include "Console.hpp"
#include <iostream>
#include <string>

namespace ui::console
{

void Console::write(std::string prompt)
{
    std::cout << prompt << std::endl;
}

std::string Console::read(std::string prompt)
{
    this->write(prompt);
    std::string value;
    std::cin >> value;
    return value;
}

int Console::readInt(std::string prompt)
{
    std::string value = this->read(prompt);
    return std::stoi(value);
}

}  // namespace ui::console
