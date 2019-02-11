// Implémentation de la classe ConfigParser ici
//
// Question 3 

#include "ConfigParser.hpp"

bool ConfigParser::initConfig(const std::string path)
{
    Command cmd;
    std::ifstream config;
    std::string commandString,s;
    size_t commaPos;

    config.open(path);
    if (config.is_open()){
        this->filePath = path;
        while(getline(config,s)){

            //if we find [ in the string 
            if((s.find_first_of('[')!= std::string::npos && commandString.size()==0)||(s.find_first_of('[')== std::string::npos && commandString.size()!=0))
            {
                //delete characters from ; to the end
                commaPos = s.find_first_of(';');
                if (commaPos != std::string::npos){
                    s=s.substr(0,commaPos);
                }
                //add the string to the commandString string only if there are characters inside.
                if(s.size()!=0){
                    commandString += s+'\n';
                }
            }
            else if (s.find_first_of('[')!= std::string::npos && commandString.size()!=0)
            {
                cmd.initCommand(commandString);
                this->commands.push_back(cmd);
                std::cout << commandString << std::endl;
                commandString = s;
            }
        }
        
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