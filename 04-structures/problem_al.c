#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node_t {
	struct node_t *next;
	int data;
};

void print_list(const struct node_t *plist) {
	struct node_t *p;
	for (p = plist; p != NULL; p = p->next)
		printf("%d ", p->data);
	printf("\n");
}

struct node_t *read_list(FILE *inp) {
	struct node_t *even_head = NULL, *even_tail = NULL;
    	struct node_t *odd_head = NULL, *odd_tail = NULL;
    	int x;

	while (fscanf(inp, "%d", &x) == 1) {
        	struct node_t *node = malloc(sizeof(struct node_t));
        	if (node == NULL) {
			printf("Error of allocation");
            		return NULL;
		}

		node->data = x;
		node->next = NULL;

		if (x % 2 == 0) {
			if (even_head == NULL) {
				even_head = even_tail = node;
			} else {
				even_tail->next = node;
				even_tail = node;
			}
		} else {
			if (odd_head == NULL) {
				odd_head = odd_tail = node;
			} else {
				odd_tail->next = node;
				odd_tail = node;
			}
		}
	}

	if (even_head == NULL)
		return odd_head;

	even_tail->next = odd_head;
	return even_head;
}

void delete_list(struct node_t *top) {
	while (top != NULL) {
		struct node_t *tmp = top;
		top = top->next;
		free(tmp);
	}	
}

int main() {
  	struct node_t *top = read_list(stdin);

    	print_list(top);

    	delete_list(top);
    	return 0;
}
