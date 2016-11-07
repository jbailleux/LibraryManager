# LibraryManager
Library manager project in C++ : School Project (INSA). Include documentations and tests

	Comment utiliser le makefile

Pas besoin de l'ouvrir et se faire mal aux yeux pour comprendre comment il fonctionne, il suffit de lire ces quelques lignes.

	Commandes disponibles

-"make" ou "make all" ou "make Projet09_BAILLEUX_COURTOIS_MARKOVSKI" : compile les fichiers .cpp, fabrique tous les .o et les déplace dans le dossier /bin. Fabrique l'executable au même niveau que le makefile. Utilise les sources présentes dans /src/. Ne fabrique pas la documentation ni l'executable pour les tests.

-"make doc" : génère la documentation du code source avec doxygen. Place les dossier /html et /latex dans le dossier /documentation. Utilise le fichier /documentation/Doxyfile.

-"make Test_Projet09_BAILLEUX_COURTOIS_MARKOVSKI" : génère l'executable qui permet d'effectuer les tests. Le place dans le dossier /test

-"make clean_all" : supprime l'executable, les .o et les dossiers de documentation.

-"make clean_bin" : supprime supprime l'executable, les .o.

-"make clean_doc" : supprime les dossiers de documentation.

-"make clean_test" : supprime l'executable qui effectue les tests.
