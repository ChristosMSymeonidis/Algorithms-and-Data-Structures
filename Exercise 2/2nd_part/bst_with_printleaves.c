/* ������: bst.c
���������: ��������� ��� ��� ���� ��������� ������� ������ ���������� (��������� �� �������)
����������: �������� ������� */

#include <stdio.h>
#include <stdlib.h>
#include "bst_with_printleaves.h"

/* ����������: ���������� �� ���� ������� ������ ����������
�������: To ������� ������ ����������
������: ��� ���� ������� ������ ���������� */
void initialize(bst_node **root) {
	*root = NULL;
}

/* ����������: ������� �� �� ������� ������ ���������� ����� �����
�������: To ������� ������ ����������
������: ���������� TRUE �� �� ������� ������ ���������� ����� ���� ��� FALSE ����������� */
boolean is_empty(bst_node *root) {
	return (root == NULL);
}

/* ����������: ������� ��� �������� ��� ������� ������ ����������
�������: To ������� ������ ���������� ��� �� �������� ���� ��������
������: �� ������������� ������� ������ ���������� */
void insert(bst_node **root, bst_element_type item) {
	bst_node *current, *parent;
	current = *root;
	parent = NULL;
	while (current != NULL) {
		parent = current;
		if (item < current->value)
			current = current->leftChild;
		else if (item > current->value)
			current = current->rightChild;
		else
			break;
	}
	if (current != NULL)
		printf("Element %d is already in the binary search tree!\n", item);
	else {
		current = (bst_node *)malloc(sizeof(bst_node));
		current->value = item;
		current->leftChild = NULL;
		current->rightChild = NULL;
		if (parent == NULL)
			*root = current;
		else if (item < parent->value)
			parent->leftChild = current;
		else
			parent->rightChild = current;
	}
}

/* ����������: ��������� ��� �������� ��� �� ������� ������ ����������
�������: To ������� ������ ���������� ��� �� �������� ��� �� ���������
������: �� ������������� ������� ������ ����������*/
void delete(bst_node **root, bst_element_type item) {
	bst_node *current; // ������ ��� �������� ��� ���� item
	bst_node *parent;  // ������� ��� ������ current
	bst_node *next; // ����������������� �������� ��� ������ ��� current
	bst_node *subTree; // ������� ���� �� ��������� ��� current
	
	/* ������ ��� ������ ���� �������� ��� ��� ������ ��� */
	search(*root, item, &current, &parent);
	if (current == NULL)
		printf("Element %d is not in the binary search tree!\n", item);
	else {
		/* ������ ���� �������� �� ��� ������ */
		if (current->leftChild != NULL && current->rightChild != NULL) {
		    /* ������ ����������������� �������� ��� ��� ������ ��� */
			next = current->rightChild;
			parent = current;
			/* �������� ���� �� �������� */
			while (next->leftChild != NULL) {
				parent = next;
				next = next->leftChild;
			}
			/* ��������� ��� ������������ ��� next ���� current ���
			������ ��� current ���� �� ������� ���� ������� */
			current->value = next->value;
			current = next;
		} 
		/* ����������� �� ��� ��������� ��� � ������ ���� �� ���� 1 ����� */
		subTree = current->leftChild;
		if (subTree == NULL)
			subTree = current->rightChild;
		if (parent == NULL) /* �� ��������� � ���� */
			*root = subTree;
		else if (parent->leftChild == current)
			parent->leftChild = subTree;
		else
			parent->rightChild = subTree;
		free(current);
	}
}

/* ����������: ������� ��� �������� ��� ������� ������ ���������� ��� ���������� ��� �����
�������: To ������� ������ ���������� ��� �� �������� ���� ���������
������: ������� ���� ��� ����� ��� ������� �� �������� ���� ��������� (� ������� ������� ��� ���� NULL �� ��� ������ �� �������� ���� ���������) ��� ������� ���� ��� ������ ��� ������ ����� (� ������� ������� ��� ���� NULL �� �� �������� ���� ��������� ����� � ����) */
void search(bst_node *root, bst_element_type item, bst_node **location, bst_node **parent) {
	*location = root;
	*parent = NULL;
	while (!(*location) != NULL) {
		if (item < (*location)->value) {
			*parent = *location;
			(*location) = (*location)->leftChild;
		}
		else if (item > (*location)->value) {
			*parent = *location;
			(*location) = (*location)->rightChild;
		}
		else 
			break;
	}
}

/* ����������: ��������� �� �������� ��� �������� ������� ���������� �� ��������������� ��������
�������: To ������� ������ ����������
������: �� �������� ��� �������� ������� ���������� �� ��������������� ����� */
void preorder_traversal(bst_node *root) {
	if (root != NULL) {
		printf("%d ", root->value);
		preorder_traversal(root->leftChild);
		preorder_traversal(root->rightChild);
	}
}

/* ����������: ��������� �� �������� ��� �������� ������� ���������� �� ���������������� ��������
�������: To ������� ������ ����������
������: �� �������� ��� �������� ������� ���������� �� ���������������� ����� */
void inorder_traversal(bst_node *root) {
	if (root != NULL) {
		inorder_traversal(root->leftChild);
		printf("%d ", root->value);
		inorder_traversal(root->rightChild);
	}
}

/* ����������: ��������� �� �������� ��� �������� ������� ���������� �� ���������������� ��������
�������: To ������� ������ ����������
������: �� �������� ��� �������� ������� ���������� �� ���������������� ����� */
void postorder_traversal(bst_node *root) {
	if (root != NULL) {
		postorder_traversal(root->leftChild);
		postorder_traversal(root->rightChild);
		printf("%d ", root->value);
	}
}
/* emfanizei ta stoixeia tou dentrou pou einai fylla
eisodos: to dentro
eksodos: ta stoxeia tou dentrou pou einai fylla
 */
 void printleaves(bst_node *root){// kaleitai me mono deikti giati den allazei to periexomeno tou dentrou
	if (root != NULL ){
			if (root->leftChild == NULL && root->rightChild == NULL)// synthiki gia na einai o komvos fyllo
			{	printf(" %d \t",root->value);// ektypwsi tou fyllou
			return ;
			}
		printleaves(root->leftChild);	// anadromiki klisi pros to aristero ypodentro tou komvou
		printleaves(root->rightChild); // anadromiki klisi pros to deksi ypodentro tou komvou
	}
}