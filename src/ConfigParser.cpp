// Implémentation de la classe ConfigParser ici
//
// Question 3 

#include "ConfigParser.hpp"

bool ConfigParser::initConfig(const std::string path)
{
    Command cmd;
    std::ifstream config;
    std::string commandString,s;
    

    config.open(path);
    if (config.is_open()){
        this->filePath = path;
        while(getline(config,s)){
            

            /*
            *if we find '[' char in the string and the command string is empty, it means we met the first [...] tag
            *if we don't find '[' chara and the command string is not empty, it means we iterate trough command parameter
            *In both cases buffer string is added to command string
            */
            if((s.find_first_of('[')!= std::string::npos && commandString.length()==0)
            ||(s.find_first_of('[')== std::string::npos && commandString.length()!=0))
            {   
                commandString += formatLine(s);
            }
            /*
            *If the '[' char is found et the command string is not empty, it mean we met an other [...] tag
            *In this case, a new command object is added to the vector with the commandString initializer
            */
            else if (s.find_first_of('[')!= std::string::npos && commandString.size()!=0)
            {
                cmd.initCommand(commandString);
                this->commands.push_back(cmd);
                commandString = s+'\n';
            }
        }
        cmd.initCommand(commandString);
        this->commands.push_back(cmd);
        
        config.close();
        return true;
    }
    std::cerr << "Impossible d'ouvrir le fichier "<<path<<std::endl;
    return false;
}

std::string ConfigParser::getFilePath(){
    return this->filePath;
}
void ConfigParser::setFilePath(const std::string path){
    this->filePath = path;
}

std::string formatLine (std::string s){
    size_t commaPos;

    //delete characters from ; to the end
    commaPos = s.find_first_of(';');
    if (commaPos != std::string::npos){
        s=s.substr(0,commaPos);
    }
    //return the formated string if it's not empty
    if(!s.empty()){
        return s+'\n';
    }
    return "";
}