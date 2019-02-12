#include "Option.hpp"

std::string Option::getOptionString(){
    return this->optionString;
}
void Option::setOptionString(const std::string s){
    this->optionString = s;
}
std::string Option::getHelpString(){
    return this->helpString;
}
void Option::setHelpString(const std::string helpString){
    this -> helpString = helpString;
}
std::string Option::getIsMandatory(){
    return this->isMandatory;
}
void Option::setIsMandatory(const std::string s){
    this -> isMandatory = s;
}
bool Option::isComplete(){
    if(this->optionString.length() == 0 || this->helpString.length() == 0 || this->isMandatory.length() == 0)
        return false;
    return true;
}
void Option::clear(){
    this-> optionString.clear();
    this->helpString.clear();
    this->isMandatory.clear();
}
Option::Option(){}
Option::Option(const std::string optionString,const std::string helpString,const std::string isMandatory){
    this->optionString = optionString;
    this->helpString = helpString;
    this->isMandatory = isMandatory;
}