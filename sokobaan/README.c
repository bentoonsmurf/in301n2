

ce readme contient

1	un arbre des includes
2	rien d autre pour le moment
3	



// ATTENTION dans fonction_affichage il y a une montagne de if
// il est conseiller de ne pas les lires de 38 a 240 
objectif a ateindre

1  lire puis stoker la partie voulu
2 jouer au sokoban
	graphic
		interface 
			au lancement 
				load mon propre sokoban
					afficher "veuillez ecrire le nom de votre fichier"
					" puis clicer sur ok "
					
					
				lire la sauvgarde
					lire le fichier sauvgarde par defaut
				new game 
					entrer un numero 7 8 9 
					que du wait_clic 4 5 6 new number
									 1 2 3 ok
			apres le lancement
				############### undo
				############### redo
				############### save
				############### quit
				###############
				restart jouer un autre niveau
				jouer un autre niveau{
					precedant suivant choisir soi meme 
					
				}
				
				
				
			
			
			
		
		
		
	sauvgarde donc ecriture dans un fichier
	chargement de partie donc lecture dans un fichier
	undo redo









arbre des includes
/*sokoban.c*/ {
	


	#include "fonction_pour_la_jouabilite.c"{
		#include <time.h>
	}
	#include "fonction_affichage.c"{
		#include <uvsqgraphics.h>
		#include "fonction_pour_undo_redo.c"{
			#include "gestion_de_fichier.c"{
				#include <stdio.h>
				#include <stdlib.h>
				#include "structures.h"
			}
			
		}
	}
}















