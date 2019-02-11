// Déclaration de la classe Command ici
//
// Question 5 
#include <vector>
#include <string>
#include "Option.hpp"
#include <sstream>
#include <algorithm>
#include <iostream>

class Command{
    private:
        std::string name;
        std::string alias;
        std::string usage;
        std::vector<Option> options;
    public:
        bool initCommand(const std::string commandString);
        std::string getName ();
        std::string getAlias ();
        std::string getUsage ();
        std::vector<Option> getOptions();
};
