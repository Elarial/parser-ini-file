#include <string>

class Option
{
private:
    std::string optionString;
    std::string helpString;
    std::string isMandatory;
public:
    std::string getOptionString();
    void setOptionString(const std::string s);
    std::string getHelpString();
    void setHelpString(const std::string helpString);
    std::string getIsMandatory();
    void setIsMandatory(const std::string s);
    bool isComplete();
    void clear();
    Option();
    Option(const std::string optionString,const std::string helpString,const std::string isMandatory);

};