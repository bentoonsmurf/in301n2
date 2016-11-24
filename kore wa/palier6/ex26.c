#include <stdio.h>




int main(int argc,char **argv){

FILE* fichier = fopen(argv[2],"r");
int i=0;

while(fgetc(fichier) != EOF){
	i++; }

printf("%d\n",i);






	
return 0;
}
