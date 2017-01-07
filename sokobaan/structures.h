// pas de fonctions ici
#define oui 42
#define non 0
#define haut 0
#define droite 90
#define bas 180
#define gauche 270
#define keyboard 2
#define arrow 1
#define clic 3
#define size_of_case 25
#define largeur_max 30 //x
#define hauteur_max 20 //y 

#define recommencer -1
#define ok 42
#define sauvgarde -1
#define lire_sauvgarde -1
#define nouvelle_partie -2
#define charger_mon_propre_sokoban -3


#define mur -2 //#
#define caisse -3 //$
#define position_de_rangement -4 //.
#define personage -5 //@
#define caisse_rangee -6 //*
#define personage_sur_rangement -7 //+
#define rien -8 // 
#define hors_du_terain -9 // meme pas un espace




typedef struct pos{ // comme POINT mais avec moins de lettres
	int x;
	int y;
}pos;

typedef struct deplacement{
	pos depart;
	int dirrection;
	int caisse_deplace; // parce que on est toujours contant de deplacer une caisse
}deplacement;

typedef struct element{// if (l->delta->depart  ==  l->delta->arrivee ) 
	deplacement delta;
	struct element* suiv;
	struct element* prev;
}element;
typedef element* liste;

typedef struct sokoban{
	int **tab;
	pos joueur;
}sokoban;

//fopen("file_name","r")
//fscanf("file_name",%d,&variable_int);
