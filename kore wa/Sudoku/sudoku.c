// sudoku.c du projet SUDOKU
// Le fichier principal qui contient le main et les fonctions de gestion du sudoku
// du projet SUDOKU

// Franck.Quessette@uvsq.fr
// Novembre 2016
#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"
#include "action.h"
#include "affichage.h"

// Initialise le sudoku à vide
SUDOKU initialiser_sudoku (){
	SUDOKU S;
	S.mode = JOUER;
	int x,y;
	for (x=0 ; x<N ; x++)
		for (y=0 ; y<N ; y++) {
			S.la_case[x][y].modifiable = 1;
			S.la_case[x][y].val = VIDE;
		}
	return S;
}
/*
SUDOKU lire_dans_fichier(FILE* fichier){
	int char_actuel;
	int x=0; int y=0;
	SUDOKU s;
	s.mode=JOUER;
	while(char_actuel != EOF){
		char_actuel= getc(fichier);
		if (char_actuel == ' ') {
			x=x+1;
		}
		else if( char_actuel == '\n') {
			y=y+1;
			}
			else {
				s.la_case[x][y].val = char_actuel;
			}
	}
return s;	
}*/

SUDOKU lire_dans_fichier(FILE* fichier){
	// fgetc(fichier) revoie le prochain char
	// c - 48 ----> char into int
	int x,y;
	SUDOKU s;
	s.mode=JOUER;
	for(y=8;y>=0;y--){
		for(x=0;x<9;x++){
			fscanf(fichier,"%d",&s.la_case[x][y].val);
			s.la_case[x][y].modifiable =(0 == s.la_case[x][y].val);  // 1 = modifiable
		}
	}
return s;
	
}

/*
lire  f   autosave
ecrire fprintf au demarage
int agrc ,char **argv
FILE* fopen(const char* nomDuFichier, const char* modeOuverture); 'r'


fscanf(fichier,"%d",&x)
char = getc(fichier) lire char par char

*/	




// Fonction qui calcule la solution du sudoku
SUDOKU resoudre_sudoku(SUDOKU S) {
	// A FINIR
	return S;
}

// Si v est dans la valeur de la case x, y de S,
// la fonction essaye les valeurs de v+1 à 9 et
// renvoie la première valeur qui est ni dans la ligne x ni dans la colonne y ni dans le bloc qui contient la case x,y
// Si aucune valeur n'est trouvée, elle renvoie 0

int verifie_ligne(SUDOKU S,int x,int y,int val){
	int i;
		for (i=0;i<8;i++){// verifier la ligne 
			if (S.la_case[(x+i)%10][y].val == val )
			return 0;
		}
	return 1;
}
int verifie_colone(SUDOKU S,int x,int y,int val){
	int i;
		for (i=0;i<8;i++){// verifier la ligne 
			if (S.la_case[x][(y+i)%10].val == val )
			return 0;
		}
	return 1;
}
int verifie_block(SUDOKU s,int x,int y,int val){
	
	int xblok=(x/3)*3;
	int yblok=(y/3)*3;
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if (s.la_case[xblok+i][yblok+j].val=val) return 0;
		}
	}
	
return 1;
}
int valeur_suivante(SUDOKU S, int x, int y) {
	int arret=  S.la_case[x][y].val ;
	int val = (arret + 1)%10;
	while(!verifie_ligne( S,x,y,val) && !verifie_colone(S,x,y,val) && !verifie_block(S,x,y,val)&&val!=arret){
		val=(val+1)%10;
	}
	// A FINIR
	// Pour le moment on renvoie la valeur+1 sans vérifier ligne, colonne et bloc
	return (S.la_case[x][y].val + 1)%10;
	return val;
}


// Modifie le sudoku en fonction de l'action
SUDOKU modifier_sudoku_action (SUDOKU S, ACTION A) {
	// CAS 1 : Clic sur un bouton : on change de mode 
	if (A.mode != GRILLE) { 
		S.mode = A.mode; 
		if (S.mode == RESOUDRE) S = resoudre_sudoku(S);
		return S; 
	}

	// CAS 2 : Clic dans la grille
	// Etape 1 : Si on est en mode SAISIR, on rend la la case  modifiable
	if (S.mode == SAISIR) S.la_case[A.x][A.y].modifiable = 1;
	// Etape 2 : Si la case est modifiable on la modifie
	if (S.la_case[A.x][A.y].modifiable) S.la_case[A.x][A.y].val = valeur_suivante(S,A.x,A.y);
	// Etape 3 : La case est non modifiable si on est en mode SAISIR et qu'elle n'est pas VIDE
	if ((S.mode == SAISIR) && (S.la_case[A.x][A.y].val != VIDE)) S.la_case[A.x][A.y].modifiable = 0;
	
	return S;
}


// Le main
int main() {
	FILE* fichier= fopen("fichier_test","r");
	SUDOKU S;
	ACTION A;
	initialiser_affichage();
	S = initialiser_sudoku();
	S = lire_dans_fichier(fichier);
	afficher_sudoku(S);
	do {
		A = recuperer_action();
		S = modifier_sudoku_action(S,A);
		afficher_sudoku(S);
	} while (mode_action(A) != QUITTER);
	exit (0);
}	
