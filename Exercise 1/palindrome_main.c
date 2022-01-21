	// ΣΥΜΕΩΝΙΔΗΣ_ΧΡΗΣΤΟΣ_1936
	#include <stdio.h>
	#include <stdlib.h>
	#include "stack.h"
  
int main ()
{
  boolean palindrome = TRUE;//  flag , true giati arxika ypothetw pws to alpharithmitiko einai palindromo 
  stack_type stackA, stackB;
  stack_element_type gramma,stoixeio_alpha,stoixeio_beta;

initialize (&stackA);
initialize (&stackB);  

int i, size;

do  {
printf ("Posoi xaraktires einai to alpharithmitiko ? \t");// elegxw megethos alpharithmitikou na einai apo 2 ws max_stack_elements
scanf ("%d", &size);// eisagw to megethos toy alpharithmitikou
}while(size>max_stack_elements || (size < 2));

char lexi[size];  

for (i = 0; i < size; i++)// Se auto to for diavazw tous xaraktires kai tous eisagw sti stoiva me push()
    {
printf ("Dose ton %do xaraktira\t", i + 1);   
scanf ("%s", &lexi[i]);      //diavasma
push (&stackA, lexi[i]);	//   push 
    } 
/*printf ("\nH leksi pou eisixthi einai :\n");  
  puts (lexi);  
  display (stackA); */
if (size % 2 == 0)// megethos a artio , kanw pop apo tin alpha kai push stin beta ws tin mesi  tou alpharithmitikou
    {				
      for (i = 0; i < size / 2; i++)
	{	  
pop (&stackA, &gramma);	  
push (&stackB, gramma);	
}    
}
  else if (size % 2 == 1)// megethos a peritto,energw opws prin kai kanw ena extra pop apo tin stoiva alpha
      {  
for (i = 0; i < size / 2; i++)
 	{			
		pop (&stackA, &gramma);	  
		push (&stackB, gramma);
}    
	pop (&stackA, &gramma);	// edw kanw to extra pop apo tin a 
    }
    /*Kanw ena display tis stoives wste na exw eikona se ti fasi vriskomai
    printf("Stoiva alpha \n");
       display (stackA);  
    printf("Stoiva beta \n");   
      display (stackB);*/
  while (!is_empty(stackA) && !is_empty(stackB)){// stin while vgazw stoixeia apo tis stoives kai ta sygkrinw
	  pop (&stackA, &stoixeio_alpha);
	  pop (&stackB, &stoixeio_beta);
    if(stoixeio_alpha != stoixeio_beta ){
      palindrome = FALSE;// an vrw diaforetika stoixeia kanw to flag false 
    }
  }
if(palindrome == TRUE){printf("\tThe alphanumerical %s is palindrome\n",lexi);}// an to flag meinei true
else{printf("\tThe alphanumerical %s isn't palindrome\n",lexi);}// an to flag allaxei se false
 /*display (stackA);  
 display (stackB);*/ 
    system ("PAUSE");
  
return 0;
}