// Les tests unitaires de la classe Command seront écrits ici
//
// avec le framework catch: https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

#include "catch.hpp"
#include "Command.hpp"


using namespace std;

TEST_CASE("Test init command", "[Command][InitCommand]") {
    /* Question 7 */
std::string commandString=
"[save]\n"
"alias=sa\n"
"usage=prend en compte le fichier mentionné en option\n"
"option.h=pour afficher de l’aide sur la commande save\n"
"option.h.mandatory=no\n"
"option.f=pour mentionner le fichier\n"
"option.f.mandatory=yes\n"
"option.c=pour créer le fichier si le fichier n’existe pas\n"
"option.c.mandatory=no";

Command cmd;
CHECK(cmd.initCommand(commandString)==true);
REQUIRE(cmd.getName()=="save");
REQUIRE(cmd.getAlias()=="sa");
REQUIRE(cmd.getUsage()=="prend en compte le fichier mentionné en option");

CHECK(cmd.getOptions().at(0).getOptionString()=="h");
CHECK(cmd.getOptions().at(0).getHelpString()=="pour afficher de l’aide sur la commande save");
CHECK(cmd.getOptions().at(0).getIsMandatory()=="no");

CHECK(cmd.getOptions().at(1).getOptionString()=="f");
CHECK(cmd.getOptions().at(1).getHelpString()=="pour mentionner le fichier");
CHECK(cmd.getOptions().at(1).getIsMandatory()=="yes");

CHECK(cmd.getOptions().at(2).getOptionString()=="c");
CHECK(cmd.getOptions().at(2).getHelpString()=="pour créer le fichier si le fichier n’existe pas");
CHECK(cmd.getOptions().at(2).getIsMandatory()=="no");


}
//Test with mixed lines, should be handled.
TEST_CASE("Test init command mixed lines","[Command Mixed]"){
std::string commandString=
    
"option.h=pour afficher de l’aide sur la commande save\n"
"alias=sa\n"
"option.h.mandatory=no\n"
"usage=prend en compte le fichier mentionné en option\n"
"[save]\n"
"option.f=pour mentionner le fichier\n"
"option.f.mandatory=yes\n"
"option.c.mandatory=no\n"
"option.c=pour créer le fichier si le fichier n’existe pas";


Command cmd;
CHECK(cmd.initCommand(commandString)==true);
REQUIRE(cmd.getName()=="save");
REQUIRE(cmd.getAlias()=="sa");
REQUIRE(cmd.getUsage()=="prend en compte le fichier mentionné en option");

CHECK(cmd.getOptions().at(0).getOptionString()=="h");
CHECK(cmd.getOptions().at(0).getHelpString()=="pour afficher de l’aide sur la commande save");
CHECK(cmd.getOptions().at(0).getIsMandatory()=="no");

CHECK(cmd.getOptions().at(1).getOptionString()=="f");
CHECK(cmd.getOptions().at(1).getHelpString()=="pour mentionner le fichier");
CHECK(cmd.getOptions().at(1).getIsMandatory()=="yes");

CHECK(cmd.getOptions().at(2).getOptionString()=="c");
CHECK(cmd.getOptions().at(2).getHelpString()=="pour créer le fichier si le fichier n’existe pas");
CHECK(cmd.getOptions().at(2).getIsMandatory()=="no");
}
