// Implémentation de la classe Command ici
// 
// Question 6 
#include"Command.hpp"

bool Command::initCommand(const std::string iniFile){
    return true;
}
std::string Command::getName (){
    return this->name;
}
std::string Command::getAlias (){
    return this->alias;
}
std::string Command::getUsage (){
    return this->usage;
}
std::vector<std::map<std::string,bool>> Command::getOptions(){
    return this->options;
}