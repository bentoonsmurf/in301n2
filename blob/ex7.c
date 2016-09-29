#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
float limite(float precision){
	
if ((limite(n)-limite(n+1)< precision )	

}
*/


float limite(float precision){
	float somme=0;
	int i=1;
	while ( ( (1/(i*i))-1/((1+i)*(1+i)) ) > precision){
		somme = somme +1/(i*i);
		i++;
	}
	return somme;
}



int main(){// non fonctionel
	srand(time(NULL));
	float a = 1/(rand() %10000);
	a= 1/1000
	float x = limite(a);
	
	printf("la fonction tend vers %f avec un precision de %f \n",x,a);
	
	
	
	
	return 0 ;	
}
