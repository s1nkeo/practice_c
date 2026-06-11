#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void bit_index(int count, unsigned *arr, int n) {
	int index = n / 8;
	int position = n % 8;

	if (index < count) {
		arr[index] ^= (1 << position);
	}

	for (int i = 0; i < count; i++) {
        	printf("%u", arr[i]);
        	if (i < count - 1) {
            		printf(" ");
        	}
    	}
	printf("\n");
}

int main() {
	int count, n, res;
	unsigned *arr;

	res = scanf("%d", &count);
	assert(res == 1);

	arr = malloc(count * sizeof(unsigned));
	if (arr == NULL) {
		printf("Allocation errof");
		abort();
	}

	for (int i = 0; i < count; i++) {
		scanf("%u", &arr[i]);
	}

	scanf("%d", &n);

	bit_index(count, arr, n);

	free(arr);

	return 0;
}
