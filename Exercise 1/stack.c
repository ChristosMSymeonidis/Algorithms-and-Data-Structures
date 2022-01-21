/* ������: stack.c
���������: ��������� ��� ��� ���� ��������� ������ (��������� �� ������)
����������: �������� ������� */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"//

/* ����������: ���������� ��� ���� ������
�������: � ������
������: ��� ���� ������ */
void initialize(stack_type *stack) {
	stack->top = -1;
}

/* ����������: ��������� �� �������� ��� �������
�������: � ������
������: �� �������� ��� ������� */
void display(stack_type stack) {
	int i;
	printf("**********\n");
	for (i = stack.top; i >= 0; i--) {
		printf("%c\n", stack.elements[i]);// allagi se %c gia na ektypwnei char
	}
	printf("**********\n\n");
}

/* ����������: ������� �� � ������ ����� ����
�������: � ������
������: ���������� TRUE �� � ������ ����� ���� ��� FALSE ����������� */
boolean is_empty(stack_type stack) {
	return stack.top == -1;
}

/* ����������: ������� �� � ������ ����� ������
�������: � ������
������: ���������� TRUE �� � ������ ����� ������ ��� FALSE ����������� */
boolean is_full(stack_type stack) {
	return stack.top == max_stack_elements - 1;
}

/* ����������: ������� ��� �������� ���� ������
�������: � ������ ��� �� �������� ���� ��������
������: � ������������� ������ */
void push(stack_type *stack, stack_element_type item) {
	if (!is_full(*stack)) {
		stack->top++;
		stack->elements[stack->top] = item;
	}
	else
		printf("----The stack is full! Cannot insert more items!----");
}

/* ����������: ������� ��� �������� ���� ������
�������: � ������ ��� �� �������� ���� ��������
������: � ������������� ������ */
void pop(stack_type *stack, stack_element_type *item) {
	if (!is_empty(*stack)) {
		*item = stack->elements[stack->top];
		stack->top--;
	}
	else
		printf("----The stack is empty! Cannot delete any items!----");
}

/* ����������: ���������� �� �������� �������� ��� ������� ����� �� �� ������
�������: � ������ ��� �� �������� ��� ��������� ���� ������
������: �� �������� ��� ��������� ���� ������  */
void top(stack_type stack, stack_element_type *item) {
	if (!is_empty(stack)) {
		*item = stack.elements[stack.top];
	}
	else
		printf("----The stack is empty!----");
}