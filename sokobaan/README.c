

ce readme contient

1	un arbre des includes
2	rien d autre pour le moment
3	



objectif a ateindre

1  lire puis stoker la partie voulu
2 jouer au sokoban
	graphic
		interface 
			au lancement 
				load mon propre sokoban
					afficher "veuillez ecrire le nom de votre fichier"
					" puis clicer sur ok "
					
					
				load
					lire le fichier sauvgarde par defaut
				new game 
					entrer un numero 7 8 9 
					que du wait_clic 4 5 6 new number
									 1 2 3 ok
			apres le lancement
				############### 
				###############
				###############
				###############
				###############
				undo redo   save
				
				
				
			
			
			
		
		
		
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















