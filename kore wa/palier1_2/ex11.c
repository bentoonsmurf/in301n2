#include <stdio.h>
#include <stdlib.h>



int syracuse(int n){
if (n==0) return 0;	
	printf("%d \n",n);
if (n==1) return 1;
if (n%2==0) return 1+siracuse(n/2);
if (n%2==1) return 1+siracuse(3*n+1);


}

int main(){
	int a;
	int n=15;
	int i;
	for (i=0;i<n;i++){
		a=siracuse(i);
		printf("il y a  %d monstrueuses iterations\n",a);
	}
	return 0;
}
