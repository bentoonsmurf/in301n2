#include <stdio.h>
#include <stdlib.h>
int trouve_b(int a){
	int b=0;
	int i;
	for (i=1;i<=a/2;i++) {
		if(!(a%i))
			b=b+i;
		}
return b;
}

int ami_deska(int n, int m){
	if (n>=m)return 0;
	int i;
	int sommeN=0;
	int sommeM=0;
	for (i=1;i<n-1;i++)
		if(n%i==0)
			sommeN=sommeN+i;
		
	for (i=1;i<m-1;i++)
		if(m%i==0)
			sommeM=sommeM+i;
	
	if (n==sommeM && m==sommeN) return 1;
	return 0;
}


void no_se(int n){
	int a;
	int b;
	for (a=1;a <= n;a++){
		b=trouve_b(a);
			if (ami_deska(a,b))
				printf("%d et %d\n",a,b);
	}

}

int main(){
	

	no_se(100000);
	
	
	
	
	
	
return 0;
}
