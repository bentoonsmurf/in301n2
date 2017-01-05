#include <stdio.h>
#include <stdlib.h>
#include "structures.h"



void recuperer_un_niveau(int que_dois_je_recuperer){
	sokoban s;
// si le joueur a demandé la sauvgarde
	if (que_dois_je_recuperer == sauvgarde){
		FILE* f =fopen("sauvgarde","r"	);	
		printf("je suis apres fopen et avans le while \n");
		int caractere =0;
		int x=0; int y=0;
		while(caractere != EOF){
			caractere = fgetc(f);
			if(caractere =='\n') {y++;
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

	//return s;
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








