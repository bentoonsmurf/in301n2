#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

void ecrire(SUDOKU s){
	FILE* f=fopen("sudoku.sudo","w");

	int i=0;
	int j=0;
	for (i=0;i<9;i++){
		for(j=0;j<9;j++){
			fprintf(f,"%d ",S.la_case[i][j].val);
		}
		fprintf(f,"\n");
	}
	fclose(f);
}


