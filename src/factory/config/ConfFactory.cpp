#include "ConfFactory.hpp"
#include <factory/console/ViewFactoryConsole.hpp>
#include <factory/qt/ViewFactoryQt.hpp>
#include <fstream>
#include <memory>
#include <sstream>

namespace factory
{

std::shared_ptr<ViewFactory> ConfFactory::viewFactory()
{
    std::ifstream file {"/home/alejandro/workspace/excursions/cfg/view_configuration.txt"};

    std::shared_ptr<ViewFactory> factory;

    std::stringstream sstream;
    if (file.is_open())
    {
        std::string line;
        getline(file, line);
        sstream.clear();
        sstream << line;
    }

    if (sstream.str() == "console")
    {
        factory = std::make_shared<console::ViewFactoryConsole>();
    }
    else if (sstream.str() == "qt")
    {
        factory = std::make_shared<qt::ViewFactoryQt>();
    }

    return factory;
}

}  // namespace factory
