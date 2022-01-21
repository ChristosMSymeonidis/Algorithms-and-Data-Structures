

/* διάσταση βοηθητικού πίνακα */
#define maxN 200000// To maxN tithetai 200000  giati einai i megisti diastasi pou kanoume taksinomisi

/* δήλωση τύπου αντικειμένων για ταξινόμηση */
typedef int item;

#define key(A) (A) /* το κλειδί της ταξινόμησης */
#define less(A, B) (key(A) < key(B)) /* σύγκριση κλειδιών */
#define exch(A, B) { item t = A; A = B; B = t; } /* αντιμετάθεση κλειδιών */
#define compexch(A, B) if (less(A, B)) exch(A, B) /* σύγκριση και αντιμετάθεση κλειδιών */

/* Αλγόριθμος ταξινόμησης με εισαγωγή (αποδοτική υλοποίηση) */
void insertionsort(item *a, int n);
/* βοηθητικός πίνακας */
item aux[maxN];
/* Αλγόριθμος ταξινόμησης με συγχώνευση */
void mergesort(item *a, int l, int r);
/* Βοηθητική συνάρτηση συγχώνευσης */
void merge(item *a, int l, int m, int r);
/* Αλγόριθμος ταξινόμησης με διαχωρισμό */
void quicksort(item *a, int l, int r);
/* Εκτύπωση στοιχείων πίνακα */
void display(item *a, int n);
/* Βοηθητική συνάρτηση διαμέρισης */
int partition(item *a, int l, int r);
// synartiseis xronometrishs
double xronometrisi_mergesort( int *a,int n);  
double xronometrisi_insertionsort(int  *a,int n);  
double xronometrisi_quicksort(int  *a,int n); 