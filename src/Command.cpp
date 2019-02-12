// Implémentation de la classe Command ici
// 
// Question 6 
#include"Command.hpp"

bool Command::initCommand(const std::string commandString){
    //Transform the command string in stream
    std::istringstream iss(commandString);
    std::string line;
    Option option;
    size_t pos;
    //iterate trough the commandString
    while(getline(iss,line,'\n')){
        //If a [ is found, set the name with the string between brackets.
        if (line.find('[')!= std::string::npos){    
            this->name = line.substr(line.find('[')+1,line.find(']')-1);
        }
        //If the balise alias exist, set the alias property with the string after the =
        else if (line.find("alias=")!= std::string::npos){
            this->alias = line.substr(line.find("alias=")+6);;
        }
         //If the balise alias exist, set the usage property with the string after the =
        else if (line.find("usage=") != std::string::npos){
            this->usage = line.substr(line.find("usage=")+6);
        }
        //If the balise option exist and it's not mandatory find the option string and set the property with it
        else if (line.find("option.") != std::string::npos && line.find("mandatory") == std::string::npos){
            pos = line.find("option.");
            option.setOptionString(line.substr(pos+7,line.find('=')-pos-7));

            pos = line .find(option.getOptionString());
            option.setHelpString(line.substr(pos+option.getOptionString().length()+1));   

        }
        //Same with the mandatory property
        else if (line.find("option.") != std::string::npos && line.find("mandatory") != std::string::npos){
            std::string mandatorySetting =  line.substr(line.find('=')+1);
            option.setIsMandatory(mandatorySetting);
           
        }
        else{
            std::cerr << "Impossible d'affecter la ligne " << line <<" à l'objet Command";
        }

        //If the option object is complete, add it to the vector
        if(option.isComplete()){
            this->options.push_back(option);
            option.clear();
        }
            
    }
    if(this->name.length() == 0 || this ->usage.length()==0 || this->alias.length()== 0){
        std::cerr << "Une erreur est apparue, un des paramètres de l'objet Command est manquant" << std::endl;
        return false;
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