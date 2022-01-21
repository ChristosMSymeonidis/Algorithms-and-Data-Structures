#include <stdlib.h>
#include <stdio.h>
  int count_digits1 (int n1) ;// dilwsi anadromikis
  int count_digits2 (int n2); // dilwsi mi anadromikis
 
 int main(){
	 int arithmos;
	 printf("Eisagete enan arithmo: \t");
	 do{
		scanf("%d",&arithmos);// eisagwgi tou akeraiou
	 }while(arithmos <=0);// elegxos na einai therikos o akeraios
		printf("Klisi anadromikis :\tO arithmos %d exei %d psifia\n",arithmos,count_digits1(arithmos));
		printf("Klisi mi anadromikis :\tO arithmos %d exei %d psifia\n",arithmos,count_digits2(arithmos));
	system("PAUSE");
	return 0;
 }
 
   int count_digits1 (int n1){
	  int psifia=1;// arxikopoihsi counter me 1 afou kathe thetikos arithmos exei toulaxiston 1 psifio
	  if(n1<10) { 
	  return 1;//monopsifios opote epestrepse monada 
	  } 
	  else {
		  return psifia=psifia+count_digits1(n1/10);//kalese tin synartisi me orisma mia taksi megethous katw kai auksise ton counter me oti epistrepsei
		   }
	}
   int count_digits2 (int n2){
	   int psifia=1;// arxikopoihsi counter me 1
	   while(n2>=10){// oso den exw monopsifio ston elegxo mou trexw auto to while
		   psifia ++;// se kathe epanalipsi auksanw ton counter psifiwn kata 1 
		   n2 = n2/10;// lamvanwntas to akeraio meros tou pphlikou ths diaresis me to 10 katevazw mia taksi megethous to orisma
		 }
	 return psifia;
    } 