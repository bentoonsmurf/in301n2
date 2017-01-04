// pas de fonctions ici
#define oui 42
#define non 0
#define haut 0
#define droite 90
#define bas 180
#define gauche 270
#define keyboard 1
#define arrow 2
#define clic 3

struct pos{ // comme POINT mais avec moins de lettres
	int x;
	int y;
};
typedef struct pos pos;


typedef struct deplacement{
	pos depart;
	pos arrivee;
	int caisse_deplace; // parce que on est toujours contant de deplacer une caisse
}deplacement;

typedef struct element{// if (l->delta->depart  ==  l->delta->arrivee ) 
	deplacement delta;
	struct element* suiv;
	struct element* prev;
}element;
typedef element* liste;

/*
une nouvelle version de la librairie uvsqgraphics est disponible sur e-campus. La nouvelle documentation est également disponible. 
Cette nouvelle version contient une nouvelle fonction : 

int wait_key_arrow_clic (char *touche, int *fleche, POINT *P); 

Cette fonction attend que l'on appuie soit sur une lettre, une flèche ou que l'on clique. 
La fonction modifie la touche, la flèche ou le point selon le premier événement qui arrive. 
La fonction renvoie le type d'événement : touche, flèche ou point 
Cette fonction est bloquante. 
*/
//fopen("file_name","r")
//fscanf("file_name",%d,&variable_int);
