// c'est la qu'il y a le main
#include "fonction_affichage.c"




int main(int argc, char ** argv){
	// exit(0); permet de quiter
init_graphics(900,600);
sokoban s;
s=init_sokoban(); // dans gestion de fichier
 // gestion de fichier


/*
s.tab[0][0]=-2;
s.tab[1][0]=-2;
s.tab[2][0]=-3;
s.tab[13][10]=-4;
s.tab[14][10]=-5;
s.tab[15][10]=-6;
s.tab[16][10]=-7;
s.tab[17][10]=-8;
s.tab[29][19]=-8;
*/


int numero_du_sokoban_selectione=100;
afficher_premiere_interface();
int g=choix_premiere_interface();


if(g==lire_sauvgarde){
	s=lire_sauvgarde_fonction(s);
}
if(g==nouvelle_partie){
	while(numero_du_sokoban_selectione >50){
		numero_du_sokoban_selectione = interface_de_selection_de_numero();}
	s=recuperer_un_niveau(numero_du_sokoban_selectione,s);
	
}
if(g==charger_mon_propre_sokoban){
	
}



printf("%d numero \n ",numero_du_sokoban_selectione);
afficher_sokoban(s);

// wait_key ...
char test_char='a';
int test_fleche=0;
POINT test_point; test_point.x=10; test_point.y=15;
int i=0;
while (i<10){
int test =  wait_key_arrow_clic_a_moi (&test_char, &test_fleche, &test_point);
if (test_char == 'Q') exit(0); 
printf("le char est %c\n",test_char); 
printf("la fleche est %d\n",test_fleche); 
printf("le point est %d x et %d y \n",test_point.x,test_point.y); 
printf("%d\n",test);
i++;
printf(" i est a %d \n",i); 
}


//wait(200);


//undo = test + memoire = memoire->prev
//redo = test + memoire = memoire->suiv
//init = memoire_clean + 

detruire_sokoban(&s);
printf(" tout va bien \n");

return 0;
}
