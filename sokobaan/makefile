all :sokoban
	./sokoban

fonction_affichage.o: fonction_affichage.c
	gcc -c `sdl-config --cflags` fonction_affichage.c

fonction_pour_la_jouabilite.o: fonction_pour_la_jouabilite.c
	gcc -c `sdl-config --cflags` fonction_pour_la_jouabilite.c

fonction_pour_undo_redo.o: fonction_pour_undo_redo.c
	gcc -c `sdl-config --cflags` fonction_pour_undo_redo.c

gestion_de_fichier.o: gestion_de_fichier.c
	gcc -c `sdl-config --cflags` gestion_de_fichier.c

sokoban.o: sokoban.c
	gcc -c sokoban.c


sokoban: sokoban.o gestion_de_fichier.o fonction_affichage.o fonction_pour_la_jouabilite.o fonction_pour_undo_redo.o
	gcc -o sokoban sokoban.o gestion_de_fichier.o fonction_affichage.o fonction_pour_la_jouabilite.o fonction_pour_undo_redo.o -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

debug_graphics:
	cd UVSQ_graphics_2016.11.26
	make install
	cd ..

clean: 
	rm sokoban

