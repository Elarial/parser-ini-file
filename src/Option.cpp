#include "Option.hpp"

char Option::getOptionChar(){
    return this->optionChar;
}
std::string Option::getHelpString(){
    return this->helpString;
}
bool Option::getIsMandatory(){
    return this->isMandatory;
}
Option::Option(char optionChar,std::string helpString,bool isMandatory){
    this->optionChar = optionChar;
    this->helpString = helpString;
    this->isMandatory = isMandatory;
}