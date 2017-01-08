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
liste l=NULL;
while (test_char!='Q'){

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
		if(test_char =='M'){
			print_liste(l);	
		}		
		if(test_char == 'U'){
			if(l!=NULL&& l->prev!=NULL){
				i--;
				s=jouer_deplacement_a_l_evers(l->delta,s);
				afficher_apres_un_deplacement(l->delta,s);
				l=l->prev;
			}
			
		}
		if(test_char == 'R'){
			if(l!=NULL&& l->suiv!=NULL){
				i++;
				l=l->suiv;
				s=jouer_deplacement(l->delta,s);
				afficher_apres_un_deplacement(l->delta,s);
			}
			
		}
		if(test_char =='K'){
			libere(l->prev);	
		}
		
	}
	
	if(test==arrow){// on se deplace
		dep=changer_deplacement(test_fleche,s);	
		if (autoriser_un_deplacement(s,dep)== oui){
			i++;
			dep.caisse_deplace=deplace_on_une_caisse(dep,s);
			printf("avant l'insert|   ");
			l=insert_debut(l,dep);
			printf(" |apres insert\n");
			s=jouer_deplacement(dep,s);
			afficher_apres_un_deplacement(dep,s);
		}
		
	}
	if(test==clic){
		if(test_point.y<100){
			if(test_point.x<280){		
				//init
			s=init_sokoban_vide();
			s=resoudre_un_choix(s,choix);
			afficher_sokoban(s);
			s.joueur=trouve_personage_dans_sokoban(s);	
			}
			if(test_point.x<650){
				// autre partie
			s=init_sokoban_vide();
			choix=choix_premiere_interface();
			s=resoudre_un_choix(s,choix);//de premiere interface
			afficher_sokoban(s);
			s.joueur=trouve_personage_dans_sokoban(s);  
			}	
		}
		// ici je sait que test_point.y > 100
		if(test_point.x>750){
			if(test_point.y<225){
				//quit
				exit(0);
			}
			if(test_point.y>475){
				//undo
				if(l!=NULL&& l->prev!=NULL){
					i--;
					s=jouer_deplacement_a_l_evers(l->delta,s);
					afficher_apres_un_deplacement(l->delta,s);
					l=l->prev;
				}
				
				
			}
			if(test_point.y>350 && test_point.y<475){
				//redo
				if(l!=NULL&& l->suiv!=NULL){
					i++;
					l=l->suiv;
					s=jouer_deplacement(l->delta,s);
					afficher_apres_un_deplacement(l->delta,s);
				}
				
			}
			if(test_point.y>225 && test_point.y<350){
				//sauvgarde
				
			}
			
		}
		
		
		
	}
	afficher_le_nombre_de_coups(i);
	

}
print_sokoban2(s);
afficher_sokoban(s);

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
