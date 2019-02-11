// Déclaration de la classe ConfigParser ici
//
// Question 2 

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Command.hpp"

class ConfigParser
{
private:
    std::string filePath;
    std::vector<Command> commands;
public:
    bool initConfig(const std::string path);
    std::string getFilePath();
    void setFilePath(const std::string path);
};
