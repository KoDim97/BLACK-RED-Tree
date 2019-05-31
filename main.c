#include <stdio.h>
#include <stdlib.h>
int x = 1;
int A[20][20];
int m = 0;
typedef struct tree_t {
		int data;
    struct tree_t * left;
    struct tree_t * right;
};


struct tree_t* AddLeft(int x, struct tree_t *tree) {
  if (tree == NULL) { // Если дерева нет, то формируем корень
    tree = (struct tree_t*)malloc(sizeof(struct tree_t)); // память под узел
    tree->data = x;   // поле данных
    tree->left =  NULL;
    tree->right = NULL; // ветви инициализируем пустотой
  }
	else   // условие добавление левого потомка
    tree->left = AddLeft(x,tree->left);
  return(tree);
}
struct tree_t * AddRight(int x, struct tree_t *tree) {
  if (tree == NULL) { // Если дерева нет, то формируем корень
    tree = (struct tree_t*)malloc(sizeof(struct tree_t)); // память под узел
    tree->data = x;   // поле данных
    tree->left =  NULL;
    tree->right = NULL; // ветви инициализируем пустотой
  }
  else    // условие добавление правого потомка
    tree->right = AddRight(x,tree->right);
  return(tree);
}
void PrintNormalTree (struct tree_t *tree, int n)
{
	if(tree != NULL)
	{
		PrintNormalTree(tree->left, n + 2);
		A[n][x] = tree->data;
		x+=2;
		PrintNormalTree(tree->right, n + 2);
	}
}
void PrintTree (struct tree_t *tree, int m)
{
	if(tree != NULL)
	{
		if (m != 0)
			printf("(");
		printf("%d", tree->data);
		if (tree->left == NULL && tree->right != NULL)
			printf("(-)");
		PrintTree(tree->left, m + 1);
		if (tree->right == NULL && tree->left != NULL)
			printf("(-)");
		PrintTree(tree->right, m + 1);
		if (m != 0)
			printf(")");
	}
}
int main(void)
{
	int i = 0, j = 0;
	struct tree_t *tree = NULL;
	tree = AddRight(1, tree);
	tree = AddRight(3, tree);
	tree = AddLeft(2, tree);
	tree->left = AddRight(5, tree->left);
	tree->left = AddLeft(4, tree->left);
	tree->right = AddLeft(6, tree->right);
	tree->right = AddRight(7, tree->right);
	tree->right->left = AddLeft(10, tree->right->left);
	tree->left->left = AddLeft(8, tree->left->left);
	tree->left->left = AddRight(9, tree->left->left);
	PrintNormalTree(tree, 1);
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			if (A[i][j] != 0)
				printf("%d", A[i][j]);
			else
				printf(" ");
		}
		printf("\n");
	}
	PrintTree(tree, m);
	return 0;
}