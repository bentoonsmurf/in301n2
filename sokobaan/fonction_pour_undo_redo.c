// gestion de listes
#include "gestion_de_fichier.c"


liste init_liste(){// mieux vaux eviter d'avoir un ellement vide
					// au debut donc je ne vais pas m'en servir
	liste new ;
	new = malloc(sizeof(struct element));
	new->suiv = NULL;
	new->prev = NULL;
	return new;
}

void print_liste(liste l){
	if (l!=NULL){
		printf("dirr %d\n",l->delta.dirrection);
		printf("caisse %d \n",l->delta.caisse_deplace);
		printf("pos.x %d pos.y %d \n",l->delta.depart.x,l->delta.depart.y);
		if (l->prev!=NULL){
			print_liste(l->prev);
		}
	}
}



void libere(liste l){
	if(l != NULL){
		libere(l->prev);
		free(l);
	}
}




liste insert_debut(liste l,deplacement x){
	liste new = malloc(sizeof(element));
	new->delta=x;
	new->suiv=NULL;
	new->prev=l;
	if(l!=NULL) l->suiv=new;
	return new;
}

