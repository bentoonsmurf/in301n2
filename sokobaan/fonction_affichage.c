//#include "structures.h"
#include <uvsqgraphics.h>
#include "fonction_pour_la_jouabilite.c"
#include "fonction_pour_undo_redo.c"
// size_of_case= 25
// hauteur_max = 20  y 
// largeur_max = 30  x

int choix_premiere_interface(){
	POINT p2;
	p2=wait_clic();
	
	if(p2.y<225)return  lire_sauvgarde;
	else if(p2.y>390)return charger_mon_propre_sokoban;
		else return nouvelle_partie;
}


void afficher_premiere_interface(){
	fill_screen(white);
	POINT p1,p2;
	p1.x=300;  p1.y=175;
	char *string ="charger la sauvgarde";
	aff_pol(string,25,p1,black);
	string = "nouvelle partie";
	p1.x=350;  p1.y=325; 
	aff_pol(string,25,p1,black);
	string = "charger son propre sokoban";
	p1.x=260;  p1.y=475; 
	aff_pol(string,25,p1,black);
	
	
	
	p1.x=0; p1.y=225; 		p2.x=900; p2.y=225;
	draw_line(p1,p2,black);
	p1.x=0; p1.y=390; 		p2.x=900; p2.y=390;
	draw_line(p1,p2,black);



}

void affiche_une_grille_de_chiffres(){
	fill_screen(white);	
	POINT p1,p2;
	char *string;
	p1.x=0; p1.y=150; 		p2.x=600; p2.y=150;
	draw_line(p1,p2,black);
	p1.x=0; p1.y=300; 		p2.x=600; p2.y=300;
	draw_line(p1,p2,black);
	p1.x=0; p1.y=450; 		p2.x=600; p2.y=450;
	draw_line(p1,p2,black);
	p1.x=200; p1.y=0; 		p2.x=200; p2.y=600;
	draw_line(p1,p2,black);
	p1.x=400; p1.y=150; 	p2.x=400; p2.y=600;
	draw_line(p1,p2,black);
	p1.x=600; p1.y=0; 		p2.x=600; p2.y=600;
	draw_line(p1,p2,black);
	
	p1.x=75;  p1.y=110;
	string="0";
	aff_pol(string,50,p1,black);
	
		p1.x=75;  p1.y=260;
	string="1";
	aff_pol(string,50,p1,black);
		p1.x=75;  p1.y=410;
	string="4";
	aff_pol(string,50,p1,black);
		p1.x=75;  p1.y=560;
	string="7";
	aff_pol(string,50,p1,black);
	
		p1.x=275;  p1.y=260;
	string="2";
	aff_pol(string,50,p1,black);
		p1.x=275;  p1.y=410;
	string="5";
	aff_pol(string,50,p1,black);
		p1.x=275;  p1.y=560;
	string="8";
	aff_pol(string,50,p1,black);
	
		p1.x=475;  p1.y=260;
	string="3";
	aff_pol(string,50,p1,black);
		p1.x=475;  p1.y=410;
	string="6";
	aff_pol(string,50,p1,black);
		p1.x=475;  p1.y=560;
	string="9";
	aff_pol(string,50,p1,black);
	// des lettres
			p1.x=700;  p1.y=410;
	string="ok";
	aff_pol(string,50,p1,black);
		p1.x=475+150;  p1.y=560;
	string="recommencer";
	aff_pol(string,30,p1,black);	
		p1.x=260;  p1.y=145;
	string="dizaines";
	aff_pol(string,15,p1,black);
		p1.x=470;  p1.y=145;
	string="unitees";
	aff_pol(string,15,p1,black);
	
	
	
}

void affiche_le_nombre_actuel(int unite,int dizaine){
	POINT p1,p2;
	char *string ;
	p1.x=202; p1.y=0; p2.x=598; p2.y=111;
	draw_fill_rectangle(p1,p2,white);
	
	// dizaines 
	if(dizaine != rien){		
		p1.x=275;  p1.y=110;
		if(dizaine == 0){
			string="0";
			aff_pol(string,50,p1,black);
		}
		if(dizaine == 1){
			string="1";
			aff_pol(string,50,p1,black);
		}
		if(dizaine == 2){
			string="2";
			aff_pol(string,50,p1,black);
		}	
		if(dizaine == 3){
			string="3";
			aff_pol(string,50,p1,black);
		}
		if(dizaine == 4){
			string="4";
			aff_pol(string,50,p1,black);
		}
		if(dizaine == 5){
			string="5";
			aff_pol(string,50,p1,black);
		}
		if(dizaine == 6){
			string="6";
			aff_pol(string,50,p1,black);
		}
		if(dizaine == 7){
			string="7";
			aff_pol(string,50,p1,black);
		}
		if(dizaine == 8){
			string="8";
			aff_pol(string,50,p1,black);
		}
		if(dizaine == 9){
			string="9";
			aff_pol(string,50,p1,black);
		}
		
		
	}
	// unite 
	//HMMMMMM le bon copie cole 
	dizaine=unite;
	if(dizaine != rien){		
		p1.x=475;  p1.y=110;
		if(dizaine == 0){
			string="0";
			aff_pol(string,50,p1,black);
		}
		if(dizaine == 1){
			string="1";
			aff_pol(string,50,p1,black);
		}
		if(dizaine == 2){
			string="2";
			aff_pol(string,50,p1,black);
		}	
		if(dizaine == 3){
			string="3";
			aff_pol(string,50,p1,black);
		}
		if(dizaine == 4){
			string="4";
			aff_pol(string,50,p1,black);
		}
		if(dizaine == 5){
			string="5";
			aff_pol(string,50,p1,black);
		}
		if(dizaine == 6){
			string="6";
			aff_pol(string,50,p1,black);
		}
		if(dizaine == 7){
			string="7";
			aff_pol(string,50,p1,black);
		}
		if(dizaine == 8){
			string="8";
			aff_pol(string,50,p1,black);
		}
		if(dizaine == 9){
			string="9";
			aff_pol(string,50,p1,black);
		}
		
		
	}
	
	
	
	
}

int sur_quoi_j_ai_clique(POINT p){
	
	if (p.x>600){
		if(p.y>450) return recommencer;
		if(p.y>300) return ok;	
		 return rien;
	}
	if (p.x>400){
		if(p.y>450) return 9;
		if(p.y>300) return 6;	
		if(p.y>150) return 3;
		 return rien;
	}
	if (p.x>200){
		if(p.y>450) return 8;
		if(p.y>300) return 5;	
		if(p.y>150) return 2;
		 return rien;
	}
	if (p.x>0){
		if(p.y>450) return 7;
		if(p.y>300) return 4;	
		if(p.y>150) return 1;
		 return 0;
	}
	return rien; // pour ne pas avoir le warning
}

int interface_de_selection_de_numero(){
	affiche_une_grille_de_chiffres();
	int valeur_finale;
	int chifre_unite=rien;
	int chifre_dizaine=rien;
	int de_transit=rien;
	POINT p1;
	
	while(!(de_transit == ok && chifre_unite != rien)){
		affiche_le_nombre_actuel(chifre_unite,chifre_dizaine);
		p1=wait_clic();
		de_transit = sur_quoi_j_ai_clique(p1);
		if(de_transit!=ok){
			if(de_transit!=recommencer){
				if(de_transit!=rien){
					if(chifre_unite==rien){
						chifre_unite=de_transit;
					}else{
						chifre_dizaine=de_transit;	
					}
					
				}
				
			}else{// else de recommencer
				chifre_unite=rien;
				chifre_dizaine=rien;
			}

		}// !=ok
	
	}
	
	
	
	if(chifre_dizaine ==rien) chifre_dizaine=0;
	
	valeur_finale = chifre_unite + chifre_dizaine*10;
	return valeur_finale;
	
	
}


void ecrire_des_truc(){
char *s = "deplacer la souris";
aff_pol(s,25,wait_clic(),white);
}



void print_sokoban2(sokoban s){
	int x,y;

	for (y=hauteur_max-1;y>=0;y--){
		for(x=0;x<largeur_max;x++){
			printf("%d",s.tab[x][y]);
		}
		printf("|%d|\n",y);
	}

}



void afficher_une_case(sokoban s,int x,int y){
	POINT p1,p2;
	p1.x=x*25; p1.y=(y*25)+124;	p2.x=(x*25)+24; p2.y=(y*25)+100;
	//il se trouve que 25 est plus court que size_of_case et en plus est ecrit en vert
	p1.y=p1.y+3;
	
	char string[1];

	

	//aff_pol(string,25,p1,blue);
	
	if(s.tab[x][y]==mur){
		string[0]='#';
		draw_fill_rectangle(p1,p2,black);
		aff_pol(string,25,p1,blue);
	}
	if(s.tab[x][y]==caisse){
		draw_fill_rectangle(p1,p2,white);
		string[0]='$';
		aff_pol(string,25,p1,marron);
	}
	if(s.tab[x][y]==position_de_rangement){
		draw_fill_rectangle(p1,p2,lightgreen);
		string[0]='.';
		aff_pol(string,25,p1,white);
	}	
	
	if(s.tab[x][y]==personage){
		draw_fill_rectangle(p1,p2,white);
		p1.y++;
		string[0]='@';
		aff_pol(string,25,p1,red);
	}
	if(s.tab[x][y]==caisse_rangee){
		draw_fill_rectangle(p1,p2,vert);
		string[0]='*';
		aff_pol(string,30,p1,marron);
	}	
	if(s.tab[x][y]==personage_sur_rangement){
		draw_fill_rectangle(p1,p2,lightgreen);
		p1.y++;
		string[0]='+';
		aff_pol(string,25,p1,red);	
	}	
	if(s.tab[x][y]==rien){
		draw_fill_rectangle(p1,p2,white);
	}	
	if(s.tab[x][y]==hors_du_terain){
		draw_fill_rectangle(p1,p2,black);
	}	
	

	
}


void afficher_la_grille(sokoban s){
	fill_screen(white);
	POINT p1,p2;
	int x,y;
	for (x=0 ; x<30 ; x++)
		for (y=0 ; y<20 ; y++) afficher_une_case(s,x,y);
	
	p1.x=0; p1.y=99; 		p2.x=900; p2.y=99;
	draw_line(p1,p2,blue);
	p1.x=750; p1.y=600; 	p2.x=750; p2.y=99;
	draw_line(p1,p2,blue);
	
	p1.x=280; p1.y=99; 		p2.x=280; p2.y=0;
	draw_line(p1,p2,blue);
	
		p1.x=751; p1.y=225; 		p2.x=900; p2.y=225;
	draw_line(p1,p2,blue);
		p1.x=751; p1.y=350; 		p2.x=900; p2.y=350;
	draw_line(p1,p2,blue);
		p1.x=751; p1.y=475; 		p2.x=900; p2.y=475;
	draw_line(p1,p2,blue);

}

void afficher_les_options_de_jeu(){
	POINT p1;
	char *string;
	
	p1.x=75;  p1.y=90;
	string="restart";
	aff_pol(string,50,p1,black);
	
	p1.x=300;  p1.y=90;
	string="jouer un autre niveau";
	aff_pol(string,50,p1,black);
	
	
	p1.x=760;  p1.y=575;
	string="undo";
	aff_pol(string,50,p1,black);
	
	p1.x=760;  p1.y=450;
	string="redo";
	aff_pol(string,50,p1,black);
	
	p1.x=760;  p1.y=450-125;
	string="save";
	aff_pol(string,50,p1,black);
	
	p1.x=760;  p1.y=200;
	string="quit";
	aff_pol(string,50,p1,black);
	

}

void afficher_sokoban(sokoban s){
	afficher_la_grille(s);
	afficher_les_options_de_jeu();
	
}






