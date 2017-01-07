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


///////////////////////////////////////////////////////////////////////////////////////
sokoban lire_sauvgarde_fonction(sokoban s){
	
		FILE* f =fopen("sauvgarde","r"	);	
		printf("je suis apres fopen et avant le while \n");
		int caractere =0;
		int x=0; int y=0;
		while(caractere != EOF){
			caractere = fgetc(f);
			printf("\n dans le while -");
			printf("\n caractere = %d ",caractere);
			printf("\n x = %d ",x);
			printf("\n y = %d ",y);
			if(caractere =='\n') {
				y++;
				x=0;
				printf("\n into the while ");
			}
			if(caractere ==13) {// allez savoir pourquoi \n ca marche pas
				y++;
				x=-1;
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
	
	return s;

}

int somme(int dizaines,int unites){
	if (dizaines == rien) return unites;
	return (10*dizaines+unites);
	
}




sokoban recuperer_un_niveau(int numero,sokoban s){
	if(numero == 0)numero =1;
	int c=32;
	int x=0; int y=0;
	int compteur1=0;	int compteur2=0;
	FILE* f =fopen("sasquatch1.xsb","r"	);	
	
	while(compteur2!=numero){
		c=getc(f);
		compteur1++;
		if(c==59){// ';'
			
			compteur2++;
			printf("ici premier ';' %dMMMMMMMMMMMMM\n",compteur2);
			if(compteur2==numero)	
			while(c!=13 && c!=EOF){c=fgetc(f);}

		}
		
			// comme ca on est a l'entree du sokoban	
	}
	printf("MMMMMMMMMMMMMMMMMMM%dMMMMMMMMMMMMM\n",compteur1);
	
			while(c != EOF &&c!=59){
			c = fgetc(f);
			printf("\n dans le while -");
			printf("\n caractere = %d ",c);
			printf("\n x = %d ",x);
			printf("\n y = %d ",y);

			if(c ==13) {// allez savoir pourquoi \n ca marche pas
				y++;
				x=-1;
				printf("\n into the while ");
			}
			if(c =='#') s.tab[x][y]= mur;
			if(c =='$') s.tab[x][y]= caisse;
			if(c =='.') s.tab[x][y]= position_de_rangement;
			if(c =='@') s.tab[x][y]= personage;
			if(c =='*') s.tab[x][y]= caisse_rangee;
			if(c =='+') s.tab[x][y]= personage_sur_rangement;
			if(c ==' ') s.tab[x][y]= rien;
			
			x++;
			printf("|%d|",s.tab[x][y]);
			
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








