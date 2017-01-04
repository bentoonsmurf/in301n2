// c'est la qu'il y a le main
/*
#include <stdio.h>
#include <stdlib.h>
c'est deja dans fonction_pour_undo_redo
*/
#include "fonction_pour_undo_redo.c"
#include "fonction_pour_la_jouabilite.c"
#include "fonction_affichage.c"

int main(int argc, char ** argv){
init_graphics(800,400);
FILE* f =fopen("sasquatch1.xsb","r"	);	

fclose(f);


char test_char='a';
int test_fleche;
POINT test_point; test_point.x=10; test_point.y=15;
int i=0;



while (i<100){
int test =  wait_key_arrow_clic (&test_char, &test_fleche, &test_point); 
printf("le char est %c\n",test_char); 
printf("la fleche est %d\n",test_fleche); 
printf("le point est %d x et %d y \n",test_point.x,test_point.y); 
printf("%d\n",test);
printf(" i est a %d \n",i); 
i++;
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
