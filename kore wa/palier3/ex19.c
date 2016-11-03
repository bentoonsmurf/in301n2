#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// t->tab  = (*t)tab

typedef struct element{
	struct element* suiv;
	int val;
}element;
typedef struct element* liste;
// je rennome un pointeur sur un element

liste creer_vide(){
	return NULL;
}
int est_vide(liste l){
return l == NULL;
}
int liste_vide(liste l){
return l==NULL;	
}

liste insert_debut(liste l,int x){
	liste new = malloc(sizeof(element));
	new->val=x;
	new->suiv=l;
	return new;
}
liste insert_fin(liste l,int x){
	if(l==NULL)return insert_debut(l,x);
	liste deb=l;
	while (l->suiv!=NULL){
		l=l->suiv;
	}
	liste new=malloc(sizeof(element));
	new->suiv=NULL;
	new->val=x;
	l->suiv=new;
	return deb;
}
void libere(liste l){
	if(!est_vide(l)){
		libere(l->suiv);
		free(l);
	}
}
// t->tab  = (*t)tab
void permute(int* a,int* b){// permute (&l.val,&l.suiv.val);
	int tmp;
	tmp= *a;
	*a=*b;
	*b=tmp;
}
liste ajout_trie(liste l,int e){
	if(liste_vide(l)){return insert_debut(l,e);}
	if (l==NULL || e<l->val){return insert_debut(l,e);}
	liste tmp=malloc(sizeof(element));
	tmp=l;
	liste new=malloc(sizeof(element));
	new->val=e;
	while (tmp->suiv!=NULL && e>tmp->suiv->val){
		tmp=tmp->suiv;}
	new->suiv=tmp->suiv;
	tmp->suiv=new;
	return l;
	
}

liste insert_trie(liste l,int x){
	//if l.suiv.val>i
		if(l==NULL)return insert_debut(l,x);
		liste deb=l;
		while ((l->suiv!=NULL) && (l->suiv->val < x)){ // on a  l<x<l.suiv
			l=l->suiv;
		}
	liste new=malloc(sizeof(element));
	new->suiv=l->suiv;
	new->val=x;
	l->suiv=new;
	return deb;
}
liste insert_trie_operationel(liste l,int n){
	liste a;
	
	if((l==NULL) || (n<= (l->val))){
		a=malloc(sizeof(element));
		if(a==NULL) exit(1);
		a->val = n;
		a->suiv = l;
		return a;
	}
	l->suiv = insert_trie_operationel(l->suiv,n);

}

int est_trie(liste l){
	if (l == NULL) return 1;
	if(l->suiv == NULL)return 1;
	else if((l->suiv)->val <= (l->val)) return 0;
	return est_trie(l->suiv);
}

void affiche2(liste l){
while(l!=NULL)
{printf("%d  " ,l->val);
l=l->suiv;}             /*  (*l).suiv==l->suiv */
}
void affiche(liste l){
	if (l!=NULL){
		printf("%d\n",l->val);
		if (l->suiv!=NULL){
			affiche(l->suiv);
		}
	}
}
int nb_elements(liste l){
	if (l==NULL)return 0;
	return 1+nb_elements(l->suiv);
}
/*
liste concat(liste l1,liste l2){
	liste tmp = l1;
	if (l1==NULL) return l2;
	while(l1->suiv!=NULL){
		l1=l1->suiv;
	}
	l1->suiv=l2;
	return tmp;
}

*/

liste concat(liste l, liste m){
	liste tmp=l;
while (tmp->suiv!=NULL){tmp=tmp->suiv;}
tmp->suiv=m;
return l;
}
liste taille_liste(liste l){
	if (l==NULL) return 0;
	return 1 + taille_liste(l->suiv);
	// return(l==NULL)? 0 : 1 +taille_liste(l->suiv);
}

liste tri_fusion(liste l1,liste l2){
	if (liste_vide(l1)) return l2;
	if (liste_vide(l2)) return l1;
	liste debut,fin;  //debul = l3
	if (l1->val<l2->val){
		debut=l1;
		fin=l1;
		l1=l1->suiv;} 
	else{
		debut=l2;
		fin=l2;
		l2=l2->suiv;}
	while (l1 != NULL && l2!=NULL){
		if(l1->val<l2->val){
			fin->suiv=l1;
			l1=l1->suiv;
			fin=fin->suiv;
		}
		else{
			fin->suiv=l2;
			l2=l2->suiv;
			fin=fin->suiv;
		}
	}
		if (l1==NULL){fin->suiv=l2;}
		else fin->suiv=l1;
	return debut;	
	
	
}

int main(){
liste l	= creer_vide(); // +1

l=ajout_trie(l,2);  
l=ajout_trie(l,5); 
l=ajout_trie(l,7);

liste l2 = creer_vide();
l2=ajout_trie(l2,1);    
l2=ajout_trie(l2,4);  
l2=ajout_trie(l2,8);  


affiche(l);
printf("\n");
affiche(l2);


printf("\n");
l=tri_fusion(l,l2);
affiche(l);

libere(l);
/*
l=insert_trie_operationel(l,2);
l=insert_trie_operationel(l,5);
l=insert_trie_operationel(l,7);
l=insert_trie_operationel(l,1);
l=insert_trie_operationel(l,4);


l=insert_debut(l,1);
l=insert_debut(l,5);
l=insert_debut(l,3);
l=insert_debut(l,7);
l=insert_debut(l,2);
l=insert_debut(l,6);
l=insert_debut(l,4);
affiche(l);
printf("\n");
//l=tri_fusion(l,l);
*/


return 0;
}
