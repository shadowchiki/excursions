#pragma once

#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include "FileDaoStruct.hpp"

template<typename T>
class GenericFileDao
{
public:
    GenericFileDao(
        std::string filePath,
        std::function<std::string(T)> saveItem,
        std::function<T(std::vector<std::string>)> readItem);

    virtual ~GenericFileDao() = default;

    std::vector<T> data();
    bool save(T newData);
    bool remove(T data);
    std::optional<T> findBy();
    std::optional<T> findBy(std::function<bool(T)>);

    static const char kSeparator;

private:
    void readFile();

private:
    std::string mFilePath;
    std::function<std::string(T)> mSaveItem;
    std::function<T(std::vector<std::string>)> mReadItem;
    std::function<bool(T)> mComparation;
    std::vector<std::shared_ptr<FileDaoStruct<T, std::string>>> mDataStored;
};
