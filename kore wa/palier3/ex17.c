#include <stdio.h>
#include <stdlib.h>


void reinit(int* p){
	
	p = NULL;
}

int main(){
/*int b = sizeof(char);
printf("%d",b);
printf("%ld",sizeof(char));
printf("ecrire");*/
int a = 1;
int* p =&a;
printf("%p\n",p);
reinit(p);
printf("%p\n",p);




return 0;

}
