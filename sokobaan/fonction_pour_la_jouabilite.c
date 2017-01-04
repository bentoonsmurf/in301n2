// pour ne pas se deplacer de 3 cases quand on cherche juste a en parcourir une
#include <time.h>

void wait(int milisec)    /*Pause pour i ms*/
{
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=((milisec*CLOCKS_PER_SEC)/1000));
}
