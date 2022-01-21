/* ������: bst.h
���������: ���������� ��� ��� ���� ��������� ������� ������ ���������� (��������� �� �������)
����������: �������� ������� */

typedef enum {
	FALSE, TRUE
} boolean;

/* ����� ��������� ��� ��������� ��� �������� ������� ���������� */
typedef int bst_element_type;

/* ������������� ������ ����� ��������� ��� ��������� ��� �������� ������� ���������� */
typedef struct bst_node bst_node;

/* ������� ��� ����� ��������� ��� �������� ������� ���������� �� ����� ������� */
struct bst_node {
	bst_element_type value;
	bst_node *leftChild, *rightChild;
};

/* ���������� �� ���� ������� ������ ���������� */
void initialize(bst_node **root);
/* ������� �� �� ������� ������ ���������� ����� ����� */
boolean is_empty(bst_node *root);
/* ������� ��� �������� ��� ������� ������ ���������� */
void insert(bst_node **root, bst_element_type item);
/* ��������� ��� �������� ��� �� ������� ������ ���������� */
void delete(bst_node **root, bst_element_type item);
/* ������� ��� �������� ��� ������� ������ ���������� ��� ���������� ��� ����� */
void search(bst_node *root, bst_element_type item, bst_node **location, bst_node **parent);
/* ��������� �� �������� ��� �������� ������� ���������� �� ��������������� �������� */
void preorder_traversal(bst_node *root);
/* ��������� �� �������� ��� �������� ������� ���������� �� ���������������� �������� */
void inorder_traversal(bst_node *root);
/* ��������� �� �������� ��� �������� ������� ���������� �� ���������������� �������� */
void postorder_traversal(bst_node *root);
/*ektypwnei ta stoixeia tou dentrou pou einai fylla */
void printleaves(bst_node *root);