#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header_file_algorithmwn.h"

int main(){
	srand(time(NULL));// arxikopoihsi gennitrias tyxaiwn arithmwn
	//clock_t totalstart,totalend;
	//totalstart=clock();
	int i,j,diastasi;
	item  *matrix,*matrix_insertionsort,*matrix_quicksort,*matrix_mergesort;// dilwseis pinakwn
	double sum_mergesort=0.0,sum_insertionsort=0.0,sum_quicksort=0.0;// metavlites gia ton ypologismo meswn orwn olwn ton diastasewn
	printf("***********************************************\n");
		for(diastasi=20000;diastasi<=200000;diastasi+=20000){ // epanalipsi for 20k ws 200k				
		matrix = (item *)malloc(diastasi*sizeof(item)); // desmeusi mnimis gia arxiko
		if (matrix == NULL) {
		printf("Error while allocating memory!!!for arxiko matrix"); 
		return -1;
		}	
		matrix_insertionsort = (item *)malloc(diastasi*sizeof(item)); // desmeusi mnimis gia insertion sort
		if (matrix_insertionsort == NULL) {
		printf("Error while allocating memory!!! for insertion sort matrix"); 
		return -1;
		}
		matrix_quicksort = (item *)malloc(diastasi*sizeof(item)); // desmeusi mnimis gia _quicksort
		if (matrix_quicksort == NULL) {
		printf("Error while allocating memory!!! for _quicksort"); 
		return -1;
		}	
		matrix_mergesort = (item *)malloc(diastasi*sizeof(item)); // desmeusi mnimis gia merge
		if (matrix_quicksort == NULL) {
		printf("Error while allocating memory!!! for _merge"); 
		return -1;
		}	
		double	mesosoros_insertionsort=0.0,mesosoros_mergesort=0.0,mesosoros_quicksort=0.0;// metavlites gia ton ypologismo meswn orwn se deka ekteleseis gia sygkekrimeni diastasi
		for(j=0;j<10;j++){
				for(i=0;i<=diastasi;i++){ // gemisma pinakwn me tous idious tyxaious arithmous
					matrix[i]=rand();// paragwgi tyxaiou akeraiou me tin rand();
					matrix_insertionsort[i]=matrix[i];
        			matrix_quicksort[i]=matrix[i];
        			matrix_mergesort[i]=matrix[i];
				} 
			mesosoros_insertionsort+=xronometrisi_insertionsort(matrix_insertionsort,diastasi);//athroizei ton xrono gia deka ekteleseis tou insertion
			mesosoros_mergesort+=xronometrisi_mergesort(matrix_mergesort,diastasi);//athroizei ton xrono gia deka ekteleseis tou mergesort
			mesosoros_quicksort+=xronometrisi_quicksort(matrix_quicksort,diastasi);//athroizei ton xrono gia deka ekteleseis tou quicksort
		}
		 //printf("***********************************************\n");
		 printf("Diastasi:%10d \t Mesos oros xronou gia 10 ekteleseis \n",diastasi);
		 /*Ektypwsi twn meswn xronwn pou kanei o algorithmos stin parousa diastasi*/
		 printf("Insertionsort:%10.4lf sec\tMergesort:%10.4lf msec\tQuicksort:%10.4lf msec\n",mesosoros_insertionsort/(10.0),1000*mesosoros_mergesort/(10.0),1000*mesosoros_quicksort/(10.0));
		 printf("***********************************************\n");
		 sum_insertionsort+=mesosoros_insertionsort/(10.0);//athroish se kathe diastasi tou mesou xronou gia deka ekteleseis , ia deka ekteleseis
		 sum_mergesort+=mesosoros_mergesort/(10.0);
		 sum_quicksort+=mesosoros_quicksort/(10.0);
		 
		  free(matrix);// apeleutherwsi twn malloc
		  free(matrix_insertionsort);
		  free(matrix_quicksort);
		  free(matrix_mergesort);
	}	
	printf("\n**********\n");	
	/*Ektypwsi tou mesou xronou pou kanei o algorithmos gia oles tis diastaseis*/	
	printf("Mesoi oroi: Insertionsort=%10.4lf sec  \t Mergesort=%10.4lf msec \t  Quicksort=%10.4lf msec \n",(sum_insertionsort)/(10.0),1000*(sum_mergesort)/(10.0),1000*(sum_quicksort)/(10.0));
	printf("**********\n");
	//totalend=clock();
	//printf("Synolikos xronos programmatos:~\t%10.4lf min \n",(((double) (totalend - totalstart)) /CLOCKS_PER_SEC)/60.0); 
	system("PAUSE");
	return 0;
	}
