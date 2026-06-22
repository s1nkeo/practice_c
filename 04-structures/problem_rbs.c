#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node_t {
    struct node_t *next;
    int data;
};

int find_max(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void insert_sorted(struct node_t **head, struct node_t *node) {
    if (*head == NULL || node->data < (*head)->data) {
        node->next = *head;
        *head = node;
        return;
    }

    struct node_t *cur = *head;
    while (cur->next && cur->next->data < node->data)
        cur = cur->next;

    node->next = cur->next;
    cur->next = node;
}

void bucket_sort(int *arr, int n) {
    struct node_t *heads[n];

    for (int i = 0; i < n; i++)
        heads[i] = NULL;

    int max = find_max(arr, n);
   	 
    for (int i = 0; i < n; i++) {
	int bucket = arr[i] / (max / n);
	if (bucket >= n)
        	bucket = n - 1;

        struct node_t *node = malloc(sizeof(struct node_t));
        node->data = arr[i];
        node->next = NULL;

        insert_sorted(&heads[bucket], node);
    }

    for (int i = 0; i < n; i++) {
        struct node_t *cur = heads[i];

        while (cur) {
            printf("%d ", cur->data);
            struct node_t *tmp = cur;
            cur = cur->next;
            free(tmp);
        }

        printf("0 ");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    assert(arr);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bucket_sort(arr, n);
    printf("\n");

    free(arr);
    return 0;
}
