#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <optional>
#include <sstream>
#include <vector>
#include "GenericFileDao_def.hpp"
#include "dao/file/FileDaoStruct_def.hpp"

template<typename T>
const char GenericFileDao<T>::kSeparator = ';';

template<typename T>
GenericFileDao<T>::GenericFileDao(
    std::string filePath,
    std::function<std::string(T)> saveItem,
    std::function<T(std::vector<std::string>)> readItem)
    : mFilePath(filePath)
    , mSaveItem(saveItem)
    , mReadItem(readItem)
{
    readFile();
}

template<typename T>
void GenericFileDao<T>::readFile()
{
    std::ifstream file {mFilePath};

    if (not file.is_open())
    {
        std::cout << "File not found" << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line))
    {
        std::stringstream stream(line);
        std::string valueEachLine;
        std::vector<std::string> splitted;
        while (getline(stream, valueEachLine, kSeparator))
        {
            splitted.push_back(valueEachLine);
        }
        auto maked = mReadItem(splitted);
        auto item = std::make_shared<FileDaoStruct<T, std::string>>(maked, stream.str() + "\n");
        mDataStored.push_back(item);
    }
}

template<typename T>
std::vector<T> GenericFileDao<T>::data()
{
    std::vector<T> aux;
    for (std::shared_ptr<FileDaoStruct<T, std::string>> value : mDataStored)
    {
        aux.push_back(value->value());
    }

    return aux;
}

template<typename T>
bool GenericFileDao<T>::save(T newData)
{
    std::ofstream file(mFilePath, std::ios::app);

    if (file.is_open())
    {
        auto data = mSaveItem(newData);
        data = data + "\n";
        file << data;
        mDataStored.push_back(std::make_shared<FileDaoStruct<T, std::string>>(newData, data));
    }
    return true;
}

template<typename T>
bool GenericFileDao<T>::remove(T data)
{
    bool removed = false;
    int sizeBeforeRemove = mDataStored.size();

    std::erase_if(
        mDataStored,
        [&removed, &data, this](std::shared_ptr<FileDaoStruct<T, std::string>> eachValue)
        { return eachValue->value() == data; });

    if (sizeBeforeRemove > mDataStored.size())
    {
        removed = true;
        std::ofstream file(mFilePath, std::ios::trunc);
        if (file.is_open())
        {
            for (std::shared_ptr<FileDaoStruct<T, std::string>> each : mDataStored)
            {
                file << each->line();
            }
        }
    }
    return removed;
}

template<typename T>
std::optional<T> GenericFileDao<T>::findBy()
{
    return findBy(mComparation);
}

template<typename T>
std::optional<T> GenericFileDao<T>::findBy(std::function<bool(T)> comparation)
{
    auto aux = data();
    auto it = std::find_if(aux.begin(), aux.end(), comparation);
    std::optional<T> data;
    if (it != aux.end())
    {
        data = *it;
    }
    return data;
}
