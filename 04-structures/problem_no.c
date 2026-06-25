#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct tree_t {
  	struct tree_t *left;
  	struct tree_t *right;
  	int data;
};

struct tree_t *createNode(int data) {
	struct tree_t *node = malloc(sizeof(struct tree_t));
	assert(node != NULL);
	node->data = data;
	node->left = NULL;
    	node->right = NULL;
    	return node;
}

struct tree_t *insert(struct tree_t *top, int data) {
	if (top == NULL)
		return createNode(data);

	if (data < top->data)
		top->left = insert(top->left, data);
	
	if (data > top->data)
		top->right = insert(top->right, data);

	return top;
}

void preorder(struct tree_t *top) {
	if (top == NULL)
        	return;

    	printf("%d ", top->data);
    	preorder(top->left);
    	preorder(top->right);
}

void freeTree(struct tree_t *top) {
    	if (top == NULL)
        	return;

    	freeTree(top->left);
    	freeTree(top->right);
    	free(top);
}

int main() {
	int n, x, res;
	struct tree_t *top = NULL;

	res = scanf("%d", &n);
	assert(res == 1);

	for (int i = 0; i < n; i++) {
        	scanf("%d", &x);
        	top = insert(top, x);
    	}

    	preorder(top);
	printf("\n");
    	freeTree(top);

    	return 0;
}
