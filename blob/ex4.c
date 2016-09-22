#include <stdlib.h>
#include <stdio.h>
// gcc -o nom_de_executable nom_du_programe

int main(){

int a=0;
int lim;
for (lim = 10; lim>0;lim --){
while(a<lim){
	
	printf(" ");
	a++;
}
a=0;
printf("*\n");
}



return 0;
}
