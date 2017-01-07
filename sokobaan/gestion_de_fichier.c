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




///////////////////////////////////////////////////////////////////////////////////////
sokoban lire_sauvgarde_fonction(sokoban s){
	
		FILE* f =fopen("sauvgarde","r");	
		printf("je suis apres fopen et avant le while \n");
		int caractere =32;
		int x=0; int y=hauteur_max-1;
		
		while(caractere != EOF){
			caractere = fgetc(f);
			if(caractere ==13) {// allez savoir pourquoi \n ca marche pas
				y--;
				x=-1;
			}
			if(caractere =='#') s.tab[x][y]= mur;
			if(caractere =='$') s.tab[x][y]= caisse;
			if(caractere =='.') s.tab[x][y]= position_de_rangement;
			if(caractere =='@') s.tab[x][y]= personage;
			if(caractere =='*') s.tab[x][y]= caisse_rangee;
			if(caractere =='+') s.tab[x][y]= personage_sur_rangement;
			if(caractere ==' ') s.tab[x][y]= rien;
			if(caractere == 10)x--;
			x++;
		//	printf("|%d|",s.tab[x][y]);
			
		}
printf("je suis apres le while \n");
		fclose(f);

printf("je suis apres fclose \n");		
	
	return s;

}
sokoban lire_sauvgarde_fonction2(sokoban s){
	int c=32;
	int x=0; int y=hauteur_max-1;
	FILE* f =fopen("sauvgarde","r"	);	
			while(c != EOF && c!=';'){
			c = fgetc(f);
			if(c ==13) {// allez savoir pourquoi \n ca marche pas
				y--;
				x= -1;
			}

			if(c =='#') s.tab[x][y]= mur;
			if(c =='$') s.tab[x][y]= caisse;
			if(c =='.') s.tab[x][y]= position_de_rangement;
			if(c =='@') s.tab[x][y]= personage;
			if(c =='*') s.tab[x][y]= caisse_rangee;
			if(c =='+') s.tab[x][y]= personage_sur_rangement;
			if(c ==' ') s.tab[x][y]= rien;
			if(c == 10)x--;

			x++;
				//		printf("|%d|",s.tab[x][y]);
		}
	
	
	fclose(f);
	return s;
}

int somme(int dizaines,int unites){
	if (dizaines == rien) return unites;
	return (10*dizaines+unites);
	
}




sokoban recuperer_un_niveau(int numero,sokoban s){
	if(numero == 0)numero =1;
	int c=32;
	int x=0; int y=hauteur_max-1;
	int compteur=0;
	FILE* f =fopen("sasquatch1.xsb","r"	);		
	while(compteur!=numero){
		c=getc(f);

		if(c==59){// ';'	
			compteur++;
			if(compteur==numero){	
				while(c!=13 && c!=EOF){c=fgetc(f);}
				c=fgetc(f);
				if(c==10)c=fgetc(f);	
			}
		}
		
			// comme ca on est a l'entree du sokoban	
	}

			while(c != EOF && c!=';'){
			c = fgetc(f);
			if(c ==13) {// allez savoir pourquoi \n ca marche pas
				y--;
				x= -1;
			}
			if(c =='#') s.tab[x][y]= mur;
			if(c =='$') s.tab[x][y]= caisse;
			if(c =='.') s.tab[x][y]= position_de_rangement;
			if(c =='@') s.tab[x][y]= personage;
			if(c =='*') s.tab[x][y]= caisse_rangee;
			if(c =='+') s.tab[x][y]= personage_sur_rangement;
			if(c ==' ') s.tab[x][y]= rien;
			if(c == 10)x--;

			x++;
				//		printf("|%d|",s.tab[x][y]);
		}
	
	
	fclose(f);
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








