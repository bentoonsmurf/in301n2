#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// t->tab  = (*t)tab
void permute(int* a,int* b){// permute (&l.val,&l.suiv.val);
	int tmp;
	tmp= *a;
	*a=*b;
	*b=tmp;
}

//  permute (&t[g],&t[i-1]) ;


int alea_int(int n){
	return rand()%n;
}
typedef struct tableau{
	int taille;
	int tab[100];
}tableau;

tableau init_tab(){
	tableau t;
	int i;
	t.taille = 10;
	for(i=0;i<10;i++){
		t.tab[i]	= alea_int(20)+1;
	}
	return t;
}
int mini(tableau t){
	if (t.taille==0) return -1;
	int min=t.tab[0];
	while(t.taille--)
	if (t.tab[t.taille]<min) min= t.tab[t.taille];
	return min;
}
void affiche(tableau t){
	while(t.taille--)
	printf("%d\n",t.tab[t.taille]);
	
}
int multi(tableau t){
	int multi = 1;
	while(t.taille--)
	multi=multi*t.tab[t.taille];
	return multi;
}

tableau decal(tableau t){
	if (t.taille == 100) {
		printf("tableau deja plein");
		return t;}
	int tmp=t.taille;
	while(t.taille--){
		permute(&t.tab[t.taille],&t.tab[t.taille+1]);
	}
	t.tab[0]=0;
	t.taille=tmp+1;
	return t;
}



long long int multi2(tableau t){
	long long int mult = 1;
	int i;
	for(i=0;i<t.taille;i++)
	mult=mult*t.tab[i];
	return mult;	
}
int partition(int t[],int g,int d){// return indice position pivo
	int i=g+1;
	int j;
	for(j=g+1;j<d;j++){
		if(t[j]<t[g]){
			t[j]=t[i];
			i++;
		}
	}
 permute (&t[g],&t[i-1]) ;
	return i-1;
}
void tri_rapide(int t[],int g,int d){
	
	int k=partition(t,g,d);
	tri_rapide(t,g,k-1);
	tri_rapide(t,k+1,d);
}


tableau tri_a_bule(tableau t){
	int i;
	int j;
	for (j=0;j<t.taille;j++){
		for (i=0;i<t.taille-1;i++){
			if (t.tab[i]>t.tab[i+1])
			permute(&t.tab[i],&t.tab[i+1]);
		
		}
	}
	return t;
}
/*
tableau ajout_trie(tableau t,int a){
	int i=0;
	while(i<
	
}

*/


int main(){	
	srand(time(NULL));
tableau	t =init_tab();
affiche(t);
printf("multi %d (int normal)\n",multi(t));
printf("multi2 %lld (long long int)\n",multi2(t));
printf("min %d \n",mini(t));
printf("%d\n",t.tab[0]);
//t=decal(t);
//tri_rapide(t.tab,0,t.taille-1);
t=tri_a_bule(t);
affiche(t);
return 0;
}
