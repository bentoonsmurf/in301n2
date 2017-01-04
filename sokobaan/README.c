

ce readme contient

1	un arbre des includes
2	rien d autre pour le moment
3	



objectif a ateindre

1  lire puis stoker la partie voulu
2 jouer au sokoban
	graphic
	sauvgarde donc ecriture dans un fichier
	chargement de partie donc lecture dans un fichier
	undo redo









arbre des includes
/*sokoban.c*/ {
	

	#include "fonction_pour_undo_redo.c"{
		#include <stdio.h>
		#include <stdlib.h>
		#include "structures.h"
	}
	#include "fonction_pour_la_jouabilite.c"{
		#include <time.h>
	}
	#include "fonction_affichage.c"{
		#include "structures.h"
		#include <uvsqgraphics.h>
	}
}
