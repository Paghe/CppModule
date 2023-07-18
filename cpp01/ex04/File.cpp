#include "ReplaceStr.hpp"

FileIo::FileIo(std::string fileName, std::string firstString, std::string secondString) :
_fileName(fileName), _firstString(firstString), _secondString(secondString) {}

void FileIo::setFileInput(std::string firstString)
{
    this->_firstString = firstString;
}

void FileIo::setFileOutput(std::string secondString)
{
    this->_secondString = secondString;
}

std::string FileIo::getInput(void)
{
    return (this->_firstString);
}

std::string FileIo::getOutput(void)
{
    return (this->_secondString);
}

void FileIo::setFileName(std::string fileName)
{
    this->_fileName = fileName;
}

std::string FileIo::getFileName(void)
{
    return (this->_fileName);
}
FileIo::~FileIo(void) {}