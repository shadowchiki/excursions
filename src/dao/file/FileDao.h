#pragma once

#include <sstream>
#include <string>
#include <vector>

class FileDao
{
public:
    FileDao();
    virtual ~FileDao() = default;

protected:
    virtual void readFile();
    virtual void saveOnFile();
    virtual void map() = 0;
    virtual std::string filePath() = 0;
    virtual void clear();

    std::vector<std::string> mData;

private:
    std::string mLine;
    std::string mValue;
    std::stringstream mStream;
};
