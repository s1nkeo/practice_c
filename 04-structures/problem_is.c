#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct tree_t {
	struct tree_t *left;
	struct tree_t *right;
	int data;
};

int recursion_bst(struct tree_t *node, int *min, int *max) {
	if (node == NULL)
		return 1;

	if (min != NULL && node->data <= *min)
		return 0;

	if (max != NULL && node->data >= *max)
        	return 0;

	return recursion_bst(node->left, min, &(node->data)) && 
		recursion_bst(node->right, &(node->data), max);
}

int check_is_bst(struct tree_t *top) {
	if (recursion_bst(top, NULL, NULL)) {
			return 1;
	} else {
	return 0;
	}
}
