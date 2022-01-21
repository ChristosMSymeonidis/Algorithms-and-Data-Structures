/* ������: stack.h
���������: ���������� ��� ��� ���� ��������� ������ (��������� �� �������)
����������: �������� ������� */

/* ������� ������ ��������� ���� ������ */
#define max_stack_elements 100

typedef enum {
	FALSE, TRUE
} boolean;

/* ����� ��������� ��� ��������� ��� ������� */
typedef char stack_element_type;/*data type changed to char */

/* ������� ��� ����� ��������� ������� �� ����� ������ */
typedef struct {
	int top;
	stack_element_type elements[max_stack_elements];
} stack_type;

/* ���������� ��� ���� ������ */
void initialize(stack_type *stack);
/* ��������� �� �������� ��� ������� */
void display(stack_type stack);
/* ������� �� � ������ ����� ����� */
boolean is_empty(stack_type stack);
/* ������� �� � ������ ����� ������ */
boolean is_full(stack_type stack);
/* ������� ��� �������� ���� ������ */
void push(stack_type *stack, stack_element_type item);
/* ��������� ��� �������� ��� ��� ������ */
void pop(stack_type *stack, stack_element_type *item);
/* ���������� �� �������� �������� ��� ������� ����� �� �� ������ */
void top(stack_type stack, stack_element_type *item);