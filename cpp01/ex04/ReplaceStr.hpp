#ifndef REPLACESTR_HPP
#define REPLACESTR_HPP

#include <fstream>
#include <string>
#include <iostream>

class FileIo
{
    private:
            std::string _fileName;
            std::string _firstString;
            std::string _secondString;
    public:
            void    setFileInput(std::string firstString);
            std::string getInput(void);
            void    setFileOutput(std::string secondString);
            std::string getOutput(void);
            void        setFileName(std::string fileName);
            std::string getFileName(void);
            FileIo(std::string fileName, std::string firstString,
                   std::string secondString);
            ~FileIo(void);
};

#endif