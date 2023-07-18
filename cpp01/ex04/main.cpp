/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:57:46 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/15 13:25:50 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceStr.hpp"

void output(std::string fileInput, std::string find, std::string replace)
{
    std::string stringOne;
    size_t  pos;

    std::ifstream inputFile(fileInput);
    if (!inputFile)
        std::cerr << fileInput + " no such file or directory" << std::endl;
    std::ofstream outFile(fileInput + ".replace");
    while (getline(inputFile, stringOne))
    {
        pos = stringOne.find(find);
        if (pos != std::string::npos)
        {
             std:: string prev = stringOne.substr(0, pos);
             std::string next = stringOne.substr(pos + find.length());
             outFile << prev << replace << next << std::endl;
        }
        else
            outFile << stringOne << std::endl;
    }
    inputFile.close();
    outFile.close();
}

int	main(int argc, char **argv)
{
    if (argc < 4)
    {
        std::cerr << "invalid format" << std::endl;
        return (0);
    }
    FileIo  File = FileIo(argv[1], argv[2], argv[3]);
    std::string fileInput;
    fileInput = File.getFileName();
    output(fileInput, argv[2], argv[3]);
    return (0);
}
