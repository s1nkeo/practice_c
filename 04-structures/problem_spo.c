#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct tree_t {
	struct tree_t *left;
	struct tree_t *right;
	int data;
};

struct tree_file_t {
  int n;
  int *topology; // 2 * n
  int *values;   // n
};

struct tree_file_t readfile(FILE *f) {
  struct tree_file_t ret;
  int res, i;

  res = fscanf(f, "%d", &ret.n);
  assert(res == 1);

  ret.topology = calloc(2 * ret.n, sizeof(int));
  ret.values = calloc(ret.n, sizeof(int));

  for (i = 0; i < 2 * ret.n; ++i) {
    res = fscanf(f, "%d", ret.topology + i);
    assert(res == 1);
  }

  for (i = 0; i < ret.n; ++i) {
    res = fscanf(f, "%d", ret.values + i);
    assert(res == 1);
  }

  return ret;
}

void free_temp(struct tree_file_t data) {
  free(data.topology);
  free(data.values);
}

void free_tree(struct tree_t *top) {
  if (top == NULL)
    return;
  free_tree(top->left);
  free_tree(top->right);
  free(top);
}

struct tree_t *create_node(int data, struct tree_t *l, struct tree_t *r) {
  struct tree_t *ret = malloc(sizeof(struct tree_t));
  assert(ret);

  ret->left = l;
  ret->right = r;
  ret->data = data;
  return ret;
}

struct tree_t *do_recover(struct tree_file_t data, int *cursor, int *curval) {
  struct tree_t *n = NULL;
  int cur = *cursor;
  int curv = *curval;
  *cursor += 1;
  if (cur < (data.n * 2) && data.topology[cur] == 1) {
    struct tree_t *l, *r;
    *curval += 1;
    l = do_recover(data, cursor, curval);
    r = do_recover(data, cursor, curval);
    assert(curv < data.n);
    n = create_node(data.values[curv], l, r);
  }
  return n;
}

struct tree_t *recover(struct tree_file_t data) {
  int cursor = 0;
  int curval = 0;
  return do_recover(data, &cursor, &curval);
}

// HERE
struct stacknode {
	struct stacknode *next;
	struct tree_t *data; 
};

void push(struct stacknode **stack, struct tree_t *data) {
	struct stacknode *tmp = calloc(1, sizeof(struct stacknode));
	if (tmp == NULL)
        	return;
	tmp->data = data;
       	tmp->next = *stack;
	*stack = tmp;
}

struct tree_t *pop(struct stacknode **top) {
	struct tree_t *data = (*top)->data;
	struct stacknode *next = (*top)->next;
	free(*top);
	(*top) = next;
	return data;
}

void print_pre(struct tree_t *top) {
	if (top == NULL) return;
	struct stacknode *s = NULL;
	push(&s, top);

      	while (s != NULL) {
		struct tree_t *node = pop(&s);
		printf("%d ", node->data);

		if (node->right)
            		push(&s, node->right);

        	if (node->left)
            		push(&s, node->left);
	}	
	
}

int main() {
  int is_search;
  struct tree_t *top;
  struct tree_file_t filetree;

  // read tree from file
  filetree = readfile(stdin);

  // recover tree
  top = recover(filetree);

  // print preorder
  print_pre(top);
  printf("\n");

  // free everything
  free_tree(top);
  free_temp(filetree);
}
