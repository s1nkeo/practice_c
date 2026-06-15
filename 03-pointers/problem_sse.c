#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int min_pos(int *arr, unsigned len, unsigned last) {
	unsigned min_pos = last;

        for (unsigned i = last + 1; i < len; i++) {
                if (arr[i] < arr[min_pos])
                min_pos = i;
        }

	return min_pos;	
}

void swap(int *v1, int *v2) {
	int tmp = *v1;
	*v1 = *v2;
	*v2 = tmp;	
}

void small_selsort(int *arr, unsigned len, unsigned last) {
	unsigned pos = min_pos(arr, len, last);
	swap(&arr[last], &arr[pos]);
}

int main() {
	unsigned len, last;
        int *arr;
        int res;

        res = scanf("%u", &len);
        assert(res == 1);

        arr = malloc(len * sizeof(int));
        assert(arr != NULL);

        for (int i = 0; i < len; i++) {
                scanf("%d", &arr[i]);
        }

	res = scanf("%u", &last);
	assert(res == 1);

	small_selsort(arr, len, last);

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	free(arr);

	return 0;
}
