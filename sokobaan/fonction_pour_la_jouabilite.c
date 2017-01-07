// pour ne pas se deplacer de 3 cases quand on cherche juste a en parcourir une
#include <time.h>
#include "fonction_affichage.c"
void wait(int milisec)    /*Pause pour i ms*/
{
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=((milisec*CLOCKS_PER_SEC)/1000));
}

int wait_key_arrow_clic_a_moi (char *touche, int *fleche, POINT *P) { // Made by qst & pc
	SDL_Event event;
	while (SDL_WaitEvent(&event)) {
		if ((event.type == SDL_KEYUP) && (event.key.keysym.sym == SDLK_ESCAPE)) exit(0);
		if ((event.type == SDL_KEYUP) && (event.key.keysym.sym == SDLK_LEFT))  { *fleche = FLECHE_GAUCHE; return EST_FLECHE; }
		if ((event.type == SDL_KEYUP) && (event.key.keysym.sym == SDLK_RIGHT)) { *fleche = FLECHE_DROITE; return EST_FLECHE; }
		if ((event.type == SDL_KEYUP) && (event.key.keysym.sym == SDLK_UP))    { *fleche = FLECHE_HAUTE;  return EST_FLECHE; }
		if ((event.type == SDL_KEYUP) && (event.key.keysym.sym == SDLK_DOWN))  { *fleche = FLECHE_BAS;    return EST_FLECHE; }
		if ((event.type == SDL_KEYUP) && ('a' <= event.key.keysym.sym) &&  (event.key.keysym.sym <= 'z'))  { *touche = event.key.keysym.sym-'a'+'A'; return EST_TOUCHE; }
//		if ((event.type == SDL_KEYUP)) { *touche = event.key.keysym.sym; return EST_TOUCHE; }
		if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT)) { P->x = event.button.x; P->y = HEIGHT-event.button.y; return EST_CLIC;}
	}
	return EST_RIEN;
}
pos trouve_personage_dans_sokoban(sokoban s){
	int x=0; int y =0;
	pos p;
	p.x=0; p.y=0;
	for(y=0;y<hauteur_max;y++)
		for (x=0;x<largeur_max;x++)
			if(s.tab[x][y]== personage){
				p.x=x;  	p.y=y;
				return p;
			}
	printf("ERREUR il n'y a pas de joueur dans le sokoban \n ");
	return p;	
}
sokoban init_sokoban_vide(){
	sokoban s;
	int i;
	s.tab=malloc(sizeof(int*)*largeur_max);
	for(i=0; i< largeur_max; i++){
		s.tab[i] = malloc(sizeof(int)*hauteur_max);
	}
	int x=0; int y =0;
	for(y=0;y<hauteur_max;y++)
		for (x=0;x<largeur_max;x++)
			s.tab[x][y]=-9;
	return s;
}

deplacement init_deplacement(sokoban s){
	deplacement dep;
	dep.depart=trouve_personage_dans_sokoban(s);
	printf("dep.x %d dep.y %d   \n",dep.depart.x,dep.depart.y);
	dep.caisse_deplace=non;
	dep.dirrection=0;
	return dep;
}
		       
int choix_premiere_interface(){
	afficher_premiere_interface();
	POINT p2;
	p2=wait_clic();
	
	if(p2.y<225)return  lire_sauvgarde;
	else if(p2.y>390)return charger_mon_propre_sokoban;
		else return nouvelle_partie;
}



sokoban resoudre_un_choix(sokoban s,int g){

int numero_du_sokoban_selectione=100;

if(g==lire_sauvgarde){
	s=lire_sauvgarde_fonction2(s);
}
if(g==nouvelle_partie){
	while(numero_du_sokoban_selectione >50){
		numero_du_sokoban_selectione = interface_de_selection_de_numero();}
	s=recuperer_un_niveau(numero_du_sokoban_selectione,s);
	
}
if(g==charger_mon_propre_sokoban){
	
}
return s;
}




sokoban jouer_deplacement(deplacement d, sokoban s){
		printf("joueur.x %d joueur.y %d  debut jouer_dep \n",s.joueur.x,s.joueur.y);
	pos destination=d.depart;
	pos au_dela=d.depart;
	if(d.dirrection==haut){	
		 destination.y++;
		 au_dela.y +=2;
		 printf(" haut ");
	 }
	if(d.dirrection==bas){
		destination.y--;
		au_dela.y -=2;
				 printf(" bas ");
	}
	if(d.dirrection==droite){
		destination.x++;
		au_dela.x +=2;
				 printf(" droite ");
	}
	if(d.dirrection==gauche){
		destination.x--;
		au_dela.x -=2;
				 printf(" gauche ");
	}
	if (d.caisse_deplace==oui){
		if(s.tab[d.depart.x][d.depart.y]==personage)
			s.tab[d.depart.x][d.depart.y]=rien;
		if(s.tab[d.depart.x][d.depart.y]==personage_sur_rangement)
			s.tab[d.depart.x][d.depart.y]=position_de_rangement;
		
		if(s.tab[destination.x][destination.y]==caisse)
			s.tab[destination.x][destination.y]=rien;
		if(s.tab[destination.x][destination.y]==caisse_rangee)
			s.tab[destination.x][destination.y]=position_de_rangement;
			
		if(s.tab[au_dela.x][au_dela.y]==rien )
			s.tab[au_dela.x][au_dela.y]=caisse;
		if(s.tab[au_dela.x][au_dela.y]==position_de_rangement)
			s.tab[au_dela.x][au_dela.y]=caisse_rangee;
		
		
		
	}else{	
		if(s.tab[d.depart.x][d.depart.y]==personage)
			s.tab[d.depart.x][d.depart.y]=rien;
		if(s.tab[d.depart.x][d.depart.y]==personage_sur_rangement)
			s.tab[d.depart.x][d.depart.y]=position_de_rangement;
		
		if(s.tab[destination.x][destination.y]==rien)
			s.tab[destination.x][destination.y]=personage;
		if(s.tab[destination.x][destination.y]==position_de_rangement)
			s.tab[destination.x][destination.y]=personage_sur_rangement;
		
	}
	
	printf("destination.x %d destination.y %d   \n",destination.x,destination.y);
	s.joueur=destination;

	printf("joueur.x %d joueur.y %d   \n",s.joueur.x,s.joueur.y);
	return s;
}

deplacement changer_deplacement(int dirr ,sokoban s){
	deplacement d;
	d.dirrection=dirr;
	d.depart=s.joueur;
	return d;
}

int deplace_on_une_caisse(deplacement d,sokoban s){
	// seulement quand le deplacement est valide
	if(d.dirrection==haut){
		if(s.tab[d.depart.x][d.depart.y+1]== caisse)return oui;
		if(s.tab[d.depart.x][d.depart.y+1]== caisse_rangee)return oui;
	}
		if(d.dirrection==bas){
		if(s.tab[d.depart.x][d.depart.y-1]== caisse)return oui;
		if(s.tab[d.depart.x][d.depart.y-1]== caisse_rangee)return oui;
	}
	
		if(d.dirrection==droite){
		if(s.tab[d.depart.x+1][d.depart.y]== caisse)return oui;
		if(s.tab[d.depart.x+1][d.depart.y]== caisse_rangee)return oui;
	}
	
		if(d.dirrection==gauche){
		if(s.tab[d.depart.x-1][d.depart.y]== caisse)return oui;
		if(s.tab[d.depart.x-1][d.depart.y]== caisse_rangee)return oui;
	}
	
	return non;
	
	
}


int autoriser_un_deplacement(sokoban s,deplacement dep){
	if(!(dep.depart.x>=0 && dep.depart.x<30 && dep.depart.y>=0 && dep.depart.y<20)) return non;//out of bound
	pos destination=dep.depart;
	pos au_dela=dep.depart;
	if(dep.dirrection==haut){	
		 destination.y++;
		 au_dela.y +=2;
		 if(destination.y>=20)return non;
		 // destination <= 19
		 
		 if(s.tab[destination.x][destination.y]== rien)return oui;
		 if(s.tab[destination.x][destination.y]== position_de_rangement)return oui;
		 //lorsque on cherche a pousser une caisse
		 
		 if(au_dela.y<20){
			if(s.tab[destination.x][destination.y]==caisse_rangee && s.tab[au_dela.x][au_dela.y]==rien)return oui;
			if(s.tab[destination.x][destination.y]==caisse_rangee && s.tab[au_dela.x][au_dela.y]==position_de_rangement)return oui;
			
			if(s.tab[destination.x][destination.y]==caisse && s.tab[au_dela.x][au_dela.y]==rien)return oui;
			if(s.tab[destination.x][destination.y]==caisse && s.tab[au_dela.x][au_dela.y]==position_de_rangement)return oui;
		  
		 } 
	 }
	if(dep.dirrection==bas){
		destination.y--;
		au_dela.y -=2;
		if(destination.y<=0)return non;
		 // destination > 0	 
		 if(s.tab[destination.x][destination.y]== rien)return oui;
		 if(s.tab[destination.x][destination.y]== position_de_rangement)return oui;
		 //lorsque on cherche a pousser une caisse	 
		 if(au_dela.y>0){
			if(s.tab[destination.x][destination.y]==caisse_rangee && s.tab[au_dela.x][au_dela.y]==rien)return oui;
			if(s.tab[destination.x][destination.y]==caisse_rangee && s.tab[au_dela.x][au_dela.y]==position_de_rangement)return oui;
			
			if(s.tab[destination.x][destination.y]==caisse && s.tab[au_dela.x][au_dela.y]==rien)return oui;
			if(s.tab[destination.x][destination.y]==caisse && s.tab[au_dela.x][au_dela.y]==position_de_rangement)return oui;
		  
		 }
	}
	if(dep.dirrection==droite){
		destination.x++;
		au_dela.x +=2;
		if(destination.x>=30)return non;
		 // destination <= 29	 
		 if(s.tab[destination.x][destination.y]== rien)return oui;
		 if(s.tab[destination.x][destination.y]== position_de_rangement)return oui;
		 //lorsque on cherche a pousser une caisse	 
		 if(au_dela.x<30){
			if(s.tab[destination.x][destination.y]==caisse_rangee && s.tab[au_dela.x][au_dela.y]==rien)return oui;
			if(s.tab[destination.x][destination.y]==caisse_rangee && s.tab[au_dela.x][au_dela.y]==position_de_rangement)return oui;
			
			if(s.tab[destination.x][destination.y]==caisse && s.tab[au_dela.x][au_dela.y]==rien)return oui;
			if(s.tab[destination.x][destination.y]==caisse && s.tab[au_dela.x][au_dela.y]==position_de_rangement)return oui;
		  
		 }
	}
	if(dep.dirrection==gauche){
		destination.x--;
		au_dela.x -=2;
		if(destination.x<=0)return non;
		 // destination <= 19 
		 if(s.tab[destination.x][destination.y]== rien)return oui;
		 if(s.tab[destination.x][destination.y]== position_de_rangement)return oui;
		 //lorsque on cherche a pousser une caisse
		 if(au_dela.x>0){
			if(s.tab[destination.x][destination.y]==caisse_rangee && s.tab[au_dela.x][au_dela.y]==rien)return oui;
			if(s.tab[destination.x][destination.y]==caisse_rangee && s.tab[au_dela.x][au_dela.y]==position_de_rangement)return oui;
			
			if(s.tab[destination.x][destination.y]==caisse && s.tab[au_dela.x][au_dela.y]==rien)return oui;
			if(s.tab[destination.x][destination.y]==caisse && s.tab[au_dela.x][au_dela.y]==position_de_rangement)return oui;
		  
		 }
	}
return non;
}



