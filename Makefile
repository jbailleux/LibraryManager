#################################################
################### Variables ###################
#################################################
OPT=-Wall -std=c++0x -c
CC=g++
SRC=src
SRCGENERAL=src/modelcentral/general
SRCAUTRE=src/modelcentral/autre
SRCSPE=src/modelcentral/specialisation/salle
DOC=documentation
#################################################



#################################################
##################### Exec ######################
#################################################
all: bin/TypeSalle.o bin/Salle.o bin/traduction.o bin/Date.o bin/Creneau.o bin/InstanceStatique.o bin/InstanceAReserver.o bin/Gestion.o bin/Controleur.o bin/Vue.o Projet09_BAILLEUX_COURTOIS_MARKOVSKI

Projet09_BAILLEUX_COURTOIS_MARKOVSKI: bin/Vue.o bin/Controleur.o bin/Gestion.o bin/InstanceAReserver.o bin/InstanceStatique.o bin/Creneau.o bin/Date.o bin/traduction.o bin/Salle.o bin/TypeSalle.o 
	$(CC) -o Projet09_BAILLEUX_COURTOIS_MARKOVSKI bin/Vue.o bin/Controleur.o bin/Gestion.o bin/InstanceAReserver.o bin/InstanceStatique.o bin/Creneau.o bin/Date.o bin/traduction.o bin/Salle.o bin/TypeSalle.o

bin/Vue.o: $(SRC)/Controleur.cpp $(SRCGENERAL)/Gestion.cpp $(SRCGENERAL)/InstanceAReserver.cpp $(SRCGENERAL)/InstanceStatique.cpp $(SRCAUTRE)/Creneau.cpp $(SRCAUTRE)/Date.cpp $(SRCAUTRE)/traduction.cpp $(SRCSPE)/Salle.cpp $(SRCSPE)/TypeSalle.cpp
	$(CC) $(OPT) $(SRC)/Vue.cpp;mv Vue.o bin/

bin/Controleur.o: $(SRC)/Controleur.cpp $(SRCGENERAL)/Gestion.cpp $(SRCGENERAL)/InstanceAReserver.cpp $(SRCGENERAL)/InstanceStatique.cpp $(SRCAUTRE)/Creneau.cpp $(SRCAUTRE)/Date.cpp $(SRCAUTRE)/traduction.cpp $(SRCSPE)/Salle.cpp $(SRCSPE)/TypeSalle.cpp
	$(CC) $(OPT) $(SRC)/Controleur.cpp;mv Controleur.o bin/

bin/Gestion.o: $(SRCGENERAL)/Gestion.cpp $(SRCGENERAL)/InstanceAReserver.cpp $(SRCGENERAL)/InstanceStatique.cpp $(SRCAUTRE)/Creneau.cpp $(SRCAUTRE)/Date.cpp $(SRCAUTRE)/traduction.cpp $(SRCSPE)/Salle.cpp $(SRCSPE)/TypeSalle.cpp
	$(CC) $(OPT) $(SRCGENERAL)/Gestion.cpp;mv Gestion.o bin/

bin/InstanceAReserver.o: $(SRCGENERAL)/InstanceAReserver.cpp $(SRCGENERAL)/InstanceStatique.cpp $(SRCAUTRE)/Creneau.cpp $(SRCAUTRE)/Date.cpp $(SRCAUTRE)/traduction.cpp $(SRCSPE)/Salle.cpp $(SRCSPE)/TypeSalle.cpp
	$(CC) $(OPT) $(SRCGENERAL)/InstanceAReserver.cpp;mv InstanceAReserver.o bin/

bin/InstanceStatique.o: $(SRCGENERAL)/InstanceStatique.cpp $(SRCAUTRE)/Creneau.cpp $(SRCAUTRE)/Date.cpp $(SRCAUTRE)/traduction.cpp $(SRCSPE)/Salle.cpp $(SRCSPE)/TypeSalle.cpp
	$(CC) $(OPT) $(SRCGENERAL)/InstanceStatique.cpp;mv InstanceStatique.o bin/

bin/Creneau.o: $(SRCAUTRE)/Creneau.cpp $(SRCAUTRE)/Date.cpp $(SRCAUTRE)/traduction.cpp
	$(CC) $(OPT) $(SRCAUTRE)/Creneau.cpp;mv Creneau.o bin/

bin/Date.o: $(SRCAUTRE)/Date.cpp $(SRCAUTRE)/traduction.cpp
	$(CC) $(OPT) $(SRCAUTRE)/Date.cpp;mv Date.o bin/

bin/traduction.o: $(SRCAUTRE)/traduction.cpp $(SRCSPE)/TypeSalle.cpp
	$(CC) $(OPT) $(SRCAUTRE)/traduction.cpp;mv traduction.o bin/

bin/Salle.o: $(SRCSPE)/Salle.cpp $(SRCSPE)/TypeSalle.cpp
	$(CC) $(OPT) $(SRCSPE)/Salle.cpp;mv Salle.o bin/

bin/TypeSalle.o :
	$(CC) $(OPT) $(SRCSPE)/TypeSalle.cpp;mv TypeSalle.o bin/
#################################################

#################################################
##################### Test ######################
#################################################
Test_Projet09_BAILLEUX_COURTOIS_MARKOVSKI: bin/main.o bin/Controleur.o bin/Gestion.o bin/InstanceAReserver.o bin/InstanceStatique.o bin/Creneau.o bin/Date.o bin/traduction.o bin/Salle.o bin/TypeSalle.o 
	$(CC) -o Test_Projet09_BAILLEUX_COURTOIS_MARKOVSKI bin/main.o bin/Controleur.o bin/Gestion.o bin/InstanceAReserver.o bin/InstanceStatique.o bin/Creneau.o bin/Date.o bin/traduction.o bin/Salle.o bin/TypeSalle.o; mv Test_Projet09_BAILLEUX_COURTOIS_MARKOVSKI test/

bin/main.o: $(SRC)/Controleur.cpp $(SRCGENERAL)/Gestion.cpp $(SRCGENERAL)/InstanceAReserver.cpp $(SRCGENERAL)/InstanceStatique.cpp $(SRCAUTRE)/Creneau.cpp $(SRCAUTRE)/Date.cpp $(SRCAUTRE)/traduction.cpp $(SRCSPE)/Salle.cpp $(SRCSPE)/TypeSalle.cpp
	$(CC) $(OPT) test/main.cpp;mv main.o bin/
#################################################	
	
#################################################
################# Documentation #################
#################################################
doc:
	rm -rf $(DOC)/html $(DOC)/latex ;doxygen $(DOC)/Doxyfile; mv html $(DOC); mv latex $(DOC)
#################################################

#################################################
#################### Clean ######################
#################################################
clean_all: 
	rm -rf *~ *.o bin/*.o Projet09_BAILLEUX_COURTOIS_MARKOVSKI test/Test_Projet09_BAILLEUX_COURTOIS_MARKOVSKI $(DOC)/html $(DOC)/latex

clean_bin:
	rm -f *~ *.o bin/*.o Projet09_BAILLEUX_COURTOIS_MARKOVSKI test/Test_Projet09_BAILLEUX_COURTOIS_MARKOVSKI

clean_test:
	rm -f *~ *.o bin/*.o test/Test_Projet09_BAILLEUX_COURTOIS_MARKOVSKI

clean_doc:
	rm -rf  $(DOC)/html $(DOC)/latex
#################################################
