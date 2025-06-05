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
        clear();
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
void FileDao::saveOnFile()
{
    std::ofstream file(filePath(), std::ios::app);
    if (file.is_open())
    {
        for (int i = 0; i < mData.size(); i++)
        {
            if (i != mData.size() - 1)
            {
                mStream << mData.at(i) << ";";
            }
            else
            {
                mStream << mData.at(i) << "\n";
            }
        }
        file << mStream.str();
    }
}
void FileDao::clear()
{
    mStream.str("");
    mStream.clear();
    mData.clear();
    mValue = "";
}
