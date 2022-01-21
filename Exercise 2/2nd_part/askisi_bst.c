#include <stdio.h>
#include <stdlib.h>
#include "bst_with_printleaves.h"

#define N 10

int main() {
	int i;
	bst_node *bsttree;
	bst_element_type num;
	
	initialize(&bsttree);
	
	FILE *fp; 
	/*
	dimiourgw  to arxeio numbers.txt   
	kai tou grafw tyxaious arithmous ws to 100
	*/
	fp = fopen("numbers.txt", "w");	
	for(i = 0; i < N; i++){
   		fprintf(fp, "%d\n", rand() % 100);
	}
	fclose(fp);
	/* 
	edw koitaw an to arxeio numbers.txt dimiourgithike kai tou graftikan oi arithmoi 
	*/
	fp = fopen("numbers.txt", "r");	
	if (fp == NULL){
		printf("Error while opening file numbers.txt!!!");
		return 1;
	}
	/* 
	afou vrika oti to arxeio yparxei 
	diavazw enan enan kathe arithmo tou
	kai ton kanw amesws insert sto dyadiko dentro bsttree
	*/
	for(i = 0; i < N; i++) {
		fscanf(fp, "%d", &num);
		insert(&bsttree, num);
	}
	fclose(fp);
	
	/* εμφάνιση δυαδικού δένδρου αναζήτησης με προδιατεταγμένη διάταξη */
	printf("----PREORDER TRAVERSAL----\n");
	preorder_traversal(bsttree);
	printf("\n");
	
	/* εμφάνιση δυαδικού δένδρου αναζήτησης με ενδοδιατεταγμένη διάταξη */
	printf("----INORDER TRAVERSAL----\n");
	inorder_traversal(bsttree);
	printf("\n");

	/* εμφάνιση δυαδικού δένδρου αναζήτησης με μεταδιατεταγμένη διάταξη */
	printf("----POSTORDER TRAVERSAL----\n");
	postorder_traversal(bsttree);
	printf("\n");

	printf("LEAVES:\t");
	printleaves(bsttree); // ektypwsi fyllwn
	
	system("PAUSE");
	return 0;
}
