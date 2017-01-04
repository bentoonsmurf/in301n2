// gestion de listes
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"


liste init_liste(){
	liste new ;
	new = malloc(sizeof(struct element));
	new->suiv = NULL;
	new->prev = NULL;
	return new;
}

liste ajout_fin(liste l,deplacement d){
	liste new= malloc(sizeof(struct element));
	liste tmp=l;
	new->delta =d;
	new->suiv = NULL;

	if(l==NULL){
	new->prev = NULL;
	return new;
	}// else implicite
	while(l->suiv != NULL){
		l=l->suiv;
	}
	l->suiv=new;
	
	return tmp;
}






void clear(liste l){
	if (l == NULL) return;
	if (l->suiv != NULL)  clear(l->suiv);
	
	free(l);
}



