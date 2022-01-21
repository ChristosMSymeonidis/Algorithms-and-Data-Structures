/* Αρχείο: stack.h
Περιγραφή: Διασύνδεση για την δομή δεδομένων στοίβα (υλοποίηση με πίνακες)
Συγγραφέας: Νικόλαος Πλόσκας */

/* μέγιστο πλήθος στοιχείων στην στοίβα */
#define max_stack_elements 100

typedef enum {
	FALSE, TRUE
} boolean;

/* τύπος δεδομένων των στοιχείων της στοίβας */
typedef char stack_element_type;/*data type changed to char */

/* ορισμός της δομής δεδομένων στοίβας με χρήση πίνακα */
typedef struct {
	int top;
	stack_element_type elements[max_stack_elements];
} stack_type;

/* Δημιουργεί την κενή στοίβα */
void initialize(stack_type *stack);
/* Εμφανίζει τα στοιχεία της στοίβας */
void display(stack_type stack);
/* Ελέγχει αν η στοίβα είναι άδεια */
boolean is_empty(stack_type stack);
/* Ελέγχει αν η στοίβα είναι γεμάτη */
boolean is_full(stack_type stack);
/* Εισάγει ένα στοιχείο στην στοίβα */
void push(stack_type *stack, stack_element_type item);
/* Διαγράφει ένα στοιχείο από την στοίβα */
void pop(stack_type *stack, stack_element_type *item);
/* Επιστρέφει το κορυφαία στοιχείο της στοίβας χωρίς να το σβήσει */
void top(stack_type stack, stack_element_type *item);