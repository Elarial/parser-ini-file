// Implémentation de la classe Command ici
// 
// Question 6 
#include"Command.hpp"

bool Command::initCommand(const std::string commandString){
    std::istringstream iss(commandString);
    std::string line;
    while(getline(iss,line,'\n')){
        
        //remove all spaces in line
        //line.erase(remove_if(line.begin(), line.end(), isspace), line.end());

        if (line.find('[')!= std::string::npos){    
            this->name = line.substr(line.find('[')+1,line.find(']')-1);
            std::cout << this->name << std::endl;
        }
        else if (line.find("alias = ")!= std::string::npos){
            this->alias = line.substr(line.find("alias = ")+8);
            std::cout << this->alias << std::endl;
        }
        else if (line.find("usage = ") != std::string::npos){
            this->usage = line.substr(line.find("usage = ")+8);
            std::cout << this->usage << std::endl;
        }
        
    }     
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
std::vector<Option> Command::getOptions(){
    return this->options;
}