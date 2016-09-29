#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 int n ;
 scanf("%d",&n);
*/

/*
int calcul (int x,int y){
		// le return est le reste
		if (x!=1){
	if (x %2){
		
		
		printf( "%d x %d \n",x,y); 
		
		calcul(x/2,y*2);
	}	
	
	else{
		calcul(x-1,y+1);
	}
	
	
}
}
*/
void calcul_egyptien(int x,int y){
	int reste=0;
	printf("   %d x %d \n = ",x,y);
	while(x!=1){
		
		if (x %2==0){
		x=x/2;
		y=y*2;
		printf( "%d x %d",x,y);
		if (reste) printf(" + %d",reste);
		printf("\n = ");
	}
	else{
		x=x-1;
		reste = reste + y;
		printf( "%d x %d",x,y);
		if (reste) printf(" + %d",reste);
		printf("\n = ");
	}
}
	reste=reste+y;
	printf ("%d\n",reste);
}

int main(){
	srand(time(NULL));
	int a = rand() %50+2;
	int b = rand() %20+1;
	calcul_egyptien(a,b);
	
return 0;	
}
