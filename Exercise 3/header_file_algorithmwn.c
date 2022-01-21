#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header_file_algorithmwn.h"

/* Λειτουργία: Αλγόριθμος ταξινόμησης με εισαγωγή (αποδοτική υλοποίηση)
Είσοδος: Ο πίνακας προς ταξινόμηση και το μέγεθος του πίνακα
Έξοδος: Ένας ταξινομημένος πίνακας */
void insertionsort(item *a, int n) {
	int i, j;
	item temp;
	/* μετακίνηση του μικρότερου στοιχείου στην αρχή του πίνακα για να παίξει το ρόλο φρουρού */
	for (i = 1; i < n; i++) {
		compexch(a[i], a[0]);
	}
	/* ταξινόμηση όλων των αντικειμένων */
	for (i = 2; i < n; i++) {
		j = i;
		temp = a[i];
		/* σύγκριση του αντικειμένου i με όλα τα αντικείμενα στα αριστερά του μέχρι να βρει το πρώτο μεγαλύτερο αντικείμενο */
		while (less(temp, a[j - 1])) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;
	}
}

/* Λειτουργία: Αλγόριθμος ταξινόμησης με συγχώνευση (αναδρομική υλοποίηση)
Είσοδος: Ο πίνακας προς ταξινόμηση και οι δείκτες l και r που δείχνουν το κομμάτι του πίνακα προς ταξινόμηση
Έξοδος: Ένας ταξινομημένος πίνακας */
void mergesort(item *a, int l, int r) {
	/* τερματισμός αναδρομικής κλήσης */
	if (r <= l) return;
	/* εύρεση σημείο διαχωρισμού */
	int m = (r + l) / 2;
	/* αναδρομική κλήση για το πρώτο μισό */
	mergesort(a, l, m);
	/* αναδρομική κλήση για το δεύτερο μισό */
	mergesort(a, m + 1, r);
	/* συγχώνευση κομματιών */
	merge(a, l, m, r);
}

/* Λειτουργία: Βοηθητική συνάρτηση συγχώνευσης
Είσοδος: Ο πίνακας προς ταξινόμηση, οι δείκτες l και r που δείχνουν το κομμάτι του πίνακα προς συγχώνευση, και ο δείκτης m που δείχνει που σταματάει ο πρώτος υποπίνακας
Έξοδος: Ένας ταξινομημένος πίνακας που συγχωνεύσει τους δύο υποπίνακες
*/
void merge(item *a, int l, int m, int r) {
	int i, j, k;
	/* αντιγραφή στον βοηθητικό πίνακα του πρώτου υποπίνακα */
	for (i = m + 1; i > l; i--) 
		aux[i - 1] = a[i - 1]; 
	/* αντιγραφή στον βοηθητικό πίνακα του αντιστραμμένου δεύτερου υποπίνακα */
	for (j = m; j < r; j++) 
		aux[r + m - j] = a[j + 1];
	/* συγχώνευση */
	for (k = l; k <= r; k++)
		if (less(aux[j], aux[i])) 
			a[k] = aux[j--]; 
		else a[k] = aux[i++];
}

/* Λειτουργία: Αλγόριθμος ταξινόμησης με διαχωρισμό
Είσοδος: Ο πίνακας προς ταξινόμηση και οι δείκτες l και r που δείχνουν το κομμάτι του πίνακα προς ταξινόμηση 
Έξοδος: Ένας ταξινομημένος πίνακας */
void quicksort(item *a, int l, int r) {
	int i;
	if (r <= l) /* τερματισμός αναδρομικής κλήσης */
		return;
	/* διαμερισμός πίνακα */
	i = partition(a, l, r);
	/* αναδρομική κλήση για το πρώτο κομμάτι */
	quicksort(a, l, i - 1);
	/* αναδρομική κλήση για το δεύτερο κομμάτι */
	quicksort(a, i + 1, r);
}

/* Λειτουργία: Βοηθητική συνάρτηση διαμέρισης
Είσοδος: Ο πίνακας προς ταξινόμηση και οι δείκτες l και r που δείχνουν το κομμάτι του πίνακα προς διαμέριση 
Έξοδος: Ένας πίνακας όπου τα στοιχεία το στοιχείο a[r] βρίσκεται στην τελική του θέση μέσα στον πίνακα, κανένα από τα στοιχεία a[1], ., a[r-1] δεν είναι μεγαλύτερο από το a[r] και κανένα από τα στοιχεία a[r+1], ., a[r] δεν είναι μικρότερο από το a[r]
 */
int partition(item *a, int l, int r) {
	int i = l, j = r - 1; /* δείκτες σάρωσης */
	item v = a[r]; /* δείκτης διαχωρισμού */
	while (1) { /* ατέρμων βρόγχος */
		/* μετακίνηση αριστερού δείκτη σάρωσης μέχρι να βρεθεί μεγαλύτερο ή ίσο στοιχείο */
		while (less(a[i], v)) i++; 
		/* μετακίνηση δεξιού δείκτη σάρωσης μέχρι να βρεθεί μικρότερο στοιχείο ή να συναντηθούν οι δύο δείκτες */
		while (less(v, a[j])) {
			j--;
			if (j == l)
				break;
		}
		/* αν συναντήθηκαν οι δείκτες ή ο αριστερός προσπέρασε τον δεξιό, τότε ο πίνακας είναι σε τάξη */
		if (i >= j)
			break;
		/* αντιμετάθεση στοιχείων */
		exch(a[i], a[j]);
		/* κίνηση δεικτών σάρωσης κατά μία θέση */
		i++;
		j--;
	}
	/* τοποθέτηση του στοιχείου διαχωρισμού στην σωστή θέση */
	exch(a[i], a[r]);
	return i;
}
/* Λειτουργία: Εκτύπωση στοιχείων πίνακα
Είσοδος: Ο πίνακας και το μέγεθος του πίνακα
Έξοδος: - */
void display(item *a, int n) {
	int i;
	printf("-----\n");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n-----\n");
}
double xronometrisi_mergesort(int *a,int n){// metrisi xronou mergesort
		clock_t startmerge,endmerge; // topikes metavlites gia tin xronometrisi
		startmerge=clock();	// "arxi xronometrou"
		mergesort(a,0,n-1); // ektelesi tou mergesort ston pinaka pou irthe apo to orisma
		endmerge =clock();// "liksi xronometrou
		//printf("----------Mergesort:%5.3lf msec\t\n",1000.0*((double) (endmerge - startmerge)) /CLOCKS_PER_SEC);
		return ((double) (endmerge - startmerge)) /CLOCKS_PER_SEC;// timi pou epistrefetai , to clocks per sec einai oros gia na epistrepsei i synartisi second
	}
double xronometrisi_insertionsort( int *a,int n){// metrisi xronou insertionsort
		clock_t startinsertion,endinsertion;// topikes metavlites gia tin xronometrisi
		startinsertion=clock();	// "arxi xronometrou"
		insertionsort(a,n);// ektelesi tou instertion ston pinaka pou irthe apo to orisma
		endinsertion =clock();// "liksi xronometrou
		//printf("----------Insertionsort:%5.3lf sec\t\n",((double)(endinsertion - startinsertion)) /CLOCKS_PER_SEC);
		return ((double) (endinsertion - startinsertion)) /CLOCKS_PER_SEC;//timi pou epistrefetai , to clocks per sec einai oros gia na epistrepsei i synartisi second
}  
double xronometrisi_quicksort( int *a,int n){//metrisi xronou quicksort
		clock_t startquick,endquick;// topikes metavlites gia tin xronometrisi
		startquick=clock();	// "arxi xronometrou"
		quicksort(a,0,n-1);// ektelesi tou quicksort ston pinaka pou irthe apo to orisma
		endquick =clock();// "liksi xronometrou
	//	printf("----------Quicksort:%5.3lf msec\t\n",1000.0*((double)(endquick - startquick)) /CLOCKS_PER_SEC);
		return ((double) (endquick - startquick)) /CLOCKS_PER_SEC;// timi pou epistrefetai , to clocks per sec einai oros gia na epistrepsei i synartisi second
}	
