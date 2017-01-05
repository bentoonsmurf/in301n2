//#include "structures.h"
#include <uvsqgraphics.h>
#include "fonction_pour_undo_redo.c"
// size of case= 25
// hauteur max = 20  y 
// largeur max = 30  x
void ecrire_des_truc(){
char *s = "deplacer la souris";
aff_pol(s,25,wait_clic(),white);
}
sokoban init_sokoban(){
	sokoban s;
	int x=0; int y =0;
	for (x=0;x<largeur_max;x++)
		for(y=0;y<hauteur_max;y++)
			s.tab[x][y]=0;
	return s;
	
	
}

void print_sokoban(sokoban s){
	int x=0; int y =0;
	for (x=0;x<largeur_max;x++){
		for(y=0;y<hauteur_max;y++){
			printf("%d",s.tab[x][y]);
		}
		
	}
	
	
	
}



void afficher_une_case(sokoban s,int x,int y){
	
	
	
	
	
}


void afficher_la_grille(sokoban s){

	int x,y;
	for (x=0 ; x<30 ; x++)
		for (y=0 ; y<20 ; y++) afficher_une_case(s,x,y);

}



