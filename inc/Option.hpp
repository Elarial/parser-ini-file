#include <string>

class Option
{
private:
    char optionChar;
    std::string helpString;
    bool isMandatory;
public:
    char getOptionChar();
    std::string getHelpString();
    bool getIsMandatory();
    Option(char optionChar,std::string helpString,bool isMandatory);
};