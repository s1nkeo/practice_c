#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *bucket(int *arr, int n, int max) {
	int *count = calloc(max + 1, sizeof(int));

	for (int i = 0; i < n; i++)
		count[arr[i]]++;

	return count;
}

int main() {
	int n, i, res;
	int *arr, *answ;
	int max = 0;

	res = scanf("%d", &n);
	assert(res == 1);

	arr = calloc(n, sizeof(int));
	for (i = 0; i < n; i++) {
		res = scanf("%d", &arr[i]);
		assert(res == 1);
		if (arr[i] > max) max = arr[i];
	}

	answ = bucket(arr, n, max);
	for (i = 0; i <= max; i++) 
		printf("%d ", answ[i]);
	printf("\n");
	
	free(arr);
	free(answ);

	return 0;
}
