#include<stdlib.h>
#include<stdlib.h>
void spaceFunction(int x){
	int i;
	for(i=0; i<x;i++) printf(" ");
}// in order to design laplace triangle
void showMatrix(int **tab, int x){
	int i, j;
	for(i=0; i<x;i++){
		spaceFunction(x-i);
		for(j=0;j<x;j++){
			spaceFunction(1);
			if(tab[i][j]==0) continue;
			printf("%d", tab[i][j]);
		}
		printf("\n");
	}
}//
int** trianglePascal(int x){
	int **tab, i, j;
	tab = (int**)malloc(sizeof(int*)*x);
	for(i=0; i<x; i++){
		tab[i]= (int*)malloc(sizeof(int)*x);
	}
	tab[0][0] = 1;
	for(j=1; j<x; j++){
		tab[0][j] = 0;
	}
	for(i=1; i<x; i++){
		for(j=0; j<=i; j++){
			if(j==0 || j==i) tab[i][j]= 1;
			else tab[i][j] = tab[i-1][j-1] + tab[i-1][j];
		}
		for(j=i+1;j<x;j++){
			tab[i][j] = 0;
		}
	}
	return tab;
}
main(){	
	int **tab, i, j, x = 5;
	tab = trianglePascal(x);
	showMatrix(tab, x);
}
