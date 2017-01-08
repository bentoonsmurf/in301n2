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


void print_sokoban_dans_fichier(sokoban s,FILE *f){//operationel
	int x,y;
	
	for (y=hauteur_max-1;y>=0;y--){
		for(x=0;x<largeur_max;x++){
			
			
			if( s.tab[x][y]== mur) fputc('#',f);
			if( s.tab[x][y]== caisse) fputc('$',f);
			if( s.tab[x][y]== position_de_rangement)fputc('.',f);
			if( s.tab[x][y]== personage)fputc('@',f);
			if( s.tab[x][y]== caisse_rangee)fputc('*',f);
			if( s.tab[x][y]== personage_sur_rangement)fputc('+',f);
			if( s.tab[x][y]== rien)fputc(' ',f);
			printf("%d",s.tab[x][y]);
			
			
		}
		printf("|%d|\n",y);
		fputc('\n',f);
	}

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








