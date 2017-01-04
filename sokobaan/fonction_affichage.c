//#include "structures.h"
#include <uvsqgraphics.h>
// size of case= 25
// hauteur max = 20    
// largeur max = 30
void ecrire_des_truc(){
char *s = "deplacer la souris";
aff_pol(s,25,wait_clic(),white);
}



void damier(){
	POINT p1;
	POINT p2;
	p1.x=10; p1.y=150;
	p2.x=10; p2.y=900;
	
	draw_line(p1,p2,white);
	
}

