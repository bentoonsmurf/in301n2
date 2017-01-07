// c'est la qu'il y a le main
#include "fonction_pour_la_jouabilite.c"



int main(int argc, char ** argv){
	// exit(0); permet de quiter
init_graphics(900,600);
sokoban s;
s=init_sokoban_vide();// dans fonction pour la jouablite
int choix=choix_premiere_interface();

s=resoudre_un_choix(s,choix);
s.joueur=trouve_personage_dans_sokoban(s);
afficher_sokoban(s);
wait(1000);
deplacement dep = init_deplacement(s);


print_sokoban2(s);
			    
// wait_key ...
char test_char='A';
int test_fleche=0;
POINT test_point; test_point.x=10; test_point.y=15;
int i=0;
int test;
while (i<100){
	i++;
	test =  wait_key_arrow_clic_a_moi (&test_char, &test_fleche, &test_point);

	printf("le char est %c\n",test_char); 
	printf("la fleche est %d\n",test_fleche); 
	printf("le point est %d x et %d y \n",test_point.x,test_point.y); 
	printf("la valeur de wait__%d\n",test);
	
	if(test==keyboard){
		if (test_char == 'Q') exit(0); 
		if (test_char == 'J'||test_char == 'S'||test_char == 'P') {
			s=init_sokoban_vide();
			choix=choix_premiere_interface();
			s=resoudre_un_choix(s,choix);//de premiere interface
			afficher_sokoban(s);
			s.joueur=trouve_personage_dans_sokoban(s);
         
		}
		if (test_char =='I'){
			s=init_sokoban_vide();
			s=resoudre_un_choix(s,choix);
			afficher_sokoban(s);
			s.joueur=trouve_personage_dans_sokoban(s);
			
		}
	}
	
	if(test==arrow){// on se deplace
		dep=changer_deplacement(test_fleche,s);	
		if (autoriser_un_deplacement(s,dep)== oui){
			dep.caisse_deplace=deplace_on_une_caisse(dep,s);
			s=jouer_deplacement(dep,s);
			afficher_apres_un_deplacement(dep,s);
		}
		
	}

	

}
print_sokoban2(s);
afficher_sokoban(s);
wait_clic();
//wait(200);


//undo = test + memoire = memoire->prev
//redo = test + memoire = memoire->suiv
//init = memoire_clean + 

detruire_sokoban(&s);
printf(" tout va bien \n");

return 0;
}

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
