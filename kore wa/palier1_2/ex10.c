#include <stdio.h>
#include <stdlib.h>

float racine(float f){
	float min=0.0;
	float mid=(0.0+f)/2.0;
	float max=f;
	while(max-min>0.01){
		
		mid=(min+max)/2.0;
		if ((mid*mid)>f)max=mid;
		else min=mid;
	}
	return mid;
	
	
}

int main(){
	float a;
	
	a=racine(15.0);
	printf("%f",a);
}
