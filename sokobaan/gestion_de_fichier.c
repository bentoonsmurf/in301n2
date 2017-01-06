#include <stdio.h>
#include <stdlib.h>
#include "structures.h"


void detruire_sokoban(sokoban *s){
	int i;
		for(i = 0; i < hauteur_max; i++){
		free(s->tab[i]);
	}
	free(s->tab);// .(*var)
}


sokoban init_sokoban(){
	sokoban s;
	int i;
	s.tab=malloc(sizeof(int*)*largeur_max);
	for(i=0; i< largeur_max; i++){
		s.tab[i] = malloc(sizeof(int)*hauteur_max);
	}
	int x=0; int y =0;
	for(y=0;y<hauteur_max;y++)
		for (x=0;x<largeur_max;x++)
			
			s.tab[x][y]=-9;
	return s;
}

sokoban recuperer_un_niveau(int que_dois_je_recuperer){
	sokoban s;
	int i;
	s.tab=malloc(sizeof(int*)*largeur_max);
	for(i = 0; i < hauteur_max; i ++){
		s.tab[i] = malloc(sizeof(int));
	}
	

	
// si le joueur a demandé la sauvgarde
	if (que_dois_je_recuperer == sauvgarde){
		FILE* f =fopen("sauvgarde","r"	);	
		printf("je suis apres fopen et avant le while \n");
		int caractere =0;
		int x=0; int y=0;
		while(caractere != EOF){
			printf("\n dans le while ");
			caractere = fgetc(f);
			printf("-");
			if(caractere =='\n') {
				y++;
				printf("\n into the while ");
			}
			if(caractere =='#') s.tab[x][y]= mur;
			if(caractere =='$') s.tab[x][y]= caisse;
			if(caractere =='.') s.tab[x][y]= position_de_rangement;
			if(caractere =='@') s.tab[x][y]= personage;
			if(caractere =='*') s.tab[x][y]= caisse_rangee;
			if(caractere =='+') s.tab[x][y]= personage_sur_rangement;
			if(caractere ==' ') s.tab[x][y]= rien;
			
			x++;
			printf("|%d|",s.tab[x][y]);
			
		}
printf("je suis apres le while \n");
		fclose(f);

printf("je suis apres fclose \n");	
	}

//si le joueur a demandé un niveau particulier

return s;
}




/*	
			if(caractere =='#') s.tab[x][y]= '#';
			if(caractere =='$') s.tab[x][y]= '$';
			if(caractere =='.') s.tab[x][y]= '.';
			if(caractere =='@') s.tab[x][y]= '@';
			if(caractere =='*') s.tab[x][y]= '*';
			if(caractere =='+') s.tab[x][y]= '+';
			if(caractere ==' ') s.tab[x][y]= ' ';
			if(caractere =='#') s.tab[x][y]= mur;
			if(caractere =='$') s.tab[x][y]= caisse;
			if(caractere =='.') s.tab[x][y]= position_de_rangement;
			if(caractere =='@') s.tab[x][y]= personage;
			if(caractere =='*') s.tab[x][y]= caisse_rangee;
			if(caractere =='+') s.tab[x][y]= personage_sur_rangement;
			if(caractere ==' ') s.tab[x][y]= rien;
*/

/*
			
			fputs("ecriture de chaine operationel\n =)",f);// remplace le contenu
			fputc('t',f);// ecrit a la fin
			//m=recuperation_du_niveau(???,???);
			
/

FILE* f =fopen("sauvgarde.txt","r+"	);	
fputs("ecriture de chaine operationel\n =)",f);// remplace le contenu
fputc('t',f);// ecrit a la fin
//m=recuperation_du_niveau(???,???);
fclose(f);

*/








