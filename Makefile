#
# Makefile suivant les recommendations de 
# https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
#

# Compilateur à utiliser
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -std=c++11 -g -O0

# Répertoires des fichiers d'en-tête
INCS = -I./inc
# Fichier s d'en-tête
INCLUDES = inc/ConfigParser.hpp inc/Command.hpp
# Fichiers source
SRCS = src/ConfigParser.cpp src/Command.cpp
# Fichiers objet
OBJS = Debug/src/ConfigParser.o Debug/src/Command.o
# Répertoires de compilation des sources
TEMP = Debug/src
# Fichier d'en-tête des tests
INCLUDES_TEST = inc/ConfigParser.hpp inc/Command.hpp
# Fichiers de tests
TESTS_SRC = test/ConfigParserTest.cpp test/CommandTest.cpp
# Fichiers objet de tests
TESTS_OBJS = Debug/test/ConfigParserTest.o Debug/src/ConfigParser.o Debug/test/CommandTest.o Debug/src/Command.o
# Répertoires de compilation des tests
TEMP_TEST = Debug/test
# Executable de test
TEST = test-config-parser


.PHONY: depend clean

all: prepare test
	@echo " "

# Préparer les dossiers de compilation
prepare: 
	@if [ ! -d $(TEMP) ]; then mkdir -p $(TEMP); fi
	@if [ ! -d $(TEMP_TEST) ]; then mkdir -p $(TEMP_TEST); echo Compilation folders prepared.; fi

# Construire les .o à partir des .cpp
Debug/src/ConfigParser.o: src/ConfigParser.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) $(INCS) -o $@ -c $<

Debug/src/Command.o: src/Command.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) $(INCS) -o $@ -c $<

test: $(TEST)
	@echo " "
	@echo \'$<\' has been compiled. Do \'make runtest\' to execute.

$(TEST): $(TESTS_OBJS)
	$(CXX) -o $@ $^

Debug/test/ConfigParserTest.o: test/ConfigParserTest.cpp $(INCLUDES_TEST)
	$(CXX) $(CXXFLAGS) $(INCS) -o $@ -c $<

Debug/test/CommandTest.o: test/CommandTest.cpp $(INCLUDES_TEST)
	$(CXX) $(CXXFLAGS) $(INCS) -o $@ -c $<

runtest:
	./$(TEST)

cleaner: clean
	$(RM) $(TEST)

clean:
	$(RM) Debug/src/*.o src/*~
	$(RM) -r Debug

depend: $(SRCS)
	makedepend $(INCS) $^

# DO NOT DELETE THIS LINE -- make depend needs it
