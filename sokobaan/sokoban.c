// c'est la qu'il y a le main
#include "fonction_pour_la_jouabilite.c"
#include "fonction_affichage.c"




int main(int argc, char ** argv){
	// exit(0); permet de quiter
init_graphics(900,600);

sokoban s=init_sokoban();
recuperer_un_niveau(sauvgarde);
print_sokoban(s);
//afficher_la_grille(s);
char test_char='a';
int test_fleche=0;
POINT test_point; test_point.x=10; test_point.y=15;
int i=0;


while (i<100){
int test =  wait_key_arrow_clic (&test_char, &test_fleche, &test_point);
if (test_char == 'Q') exit(0); 
printf("le char est %c\n",test_char); 
printf("la fleche est %d\n",test_fleche); 
printf("le point est %d x et %d y \n",test_point.x,test_point.y); 
printf("%d\n",test);
i++;
printf(" i est a %d \n",i); 
wait(200);
}
/*
test =  wait_key_arrow_clic (&test_char, &test_fleche, &test_point);
printf("le char est %c\n",test_char); 
printf("la fleche est %d\n",test_fleche); 
printf("le point est %d x et %d y \n",test_point.x,test_point.y); 
printf("%d\n",test);
*/
//undo = test + memoire = memoire->prev
//redo = test + memoire = memoire->suiv
//init = memoire_clean + 


return 0;
}
