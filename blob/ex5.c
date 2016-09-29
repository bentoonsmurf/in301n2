#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// gcc -Wall -o nom_exec fichier.c
void conversion(int a){
	int heure=a/3600;
	int minute=a/60 - heure*60;
	int sec=a%60;
	
	printf("%d sec correspond a \n",a);
	if (heure==1)printf("%d heure ",heure);
	else printf("%d heures ",heure);
	
	if (minute==1)printf("%d minute ",minute);
	else printf("%d minutes ",minute);
	
	if (sec==1) printf("%d seconde",sec);
	else printf("%d secondes",sec);

	
	
	
	
}


int main(){
	srand(time(NULL));
	int a = rand() %10000 +60;
	conversion(a);
	
	return 0;
}
