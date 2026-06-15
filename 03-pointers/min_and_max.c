#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void min_and_max(int arr[], unsigned len) {
	unsigned i;
	int min = arr[0];
	int max = arr[0];

	if (len == 0) {
        	printf("0 0\n");
		return;
	}

	for (i = 0; i < len; i++) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
            		max = arr[i];
	}
	printf("%d %d\n", min, max);
}

int main() {
	unsigned len;
	int *arr;
	int res;

	res = scanf("%u", &len);
	assert(res == 1);

	arr = malloc(len * sizeof(int));
    	assert(arr != NULL);

	for (int i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
	}

	min_and_max(arr, len);
	
	free(arr);

	return 0;
}
