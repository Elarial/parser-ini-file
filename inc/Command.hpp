// Déclaration de la classe Command ici
//
// Question 5 
#include <vector>
#include <string>
#include <map>

class Command{
    private:
        std::string name;
        std::string alias;
        std::string usage;
        std::vector<std::map<std::string,bool>> options;
    public:
        bool initCommand(const std::string command);
        std::string getName ();
        std::string getAlias ();
        std::string getUsage ();
        std::vector<std::map<std::string,bool>> getOptions();
};
