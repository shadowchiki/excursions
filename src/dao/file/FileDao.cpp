#include "FileDao.h"
#include <fstream>
#include <iostream>

FileDao::FileDao()
    : mData()
    , mLine()
    , mValue()
    , mStream()
{
}

void FileDao::readFile()
{
    std::ifstream file {filePath()};

    if (file.is_open())
    {
        while (file)
        {
            getline(file, mLine);
            mStream.clear();
            mStream << mLine;
            while (getline(mStream, mValue, ';'))
            {
                mData.push_back(mValue);
            }
            if (mData.size() > 0)
            {
                map();
            }
            mData.clear();
            mValue = "";
        }
    }
    else
    {
        std::cout << "File not found" << std::endl;
    }
}
