// pour ne pas se deplacer de 3 cases quand on cherche juste a en parcourir une
#include <time.h>

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
