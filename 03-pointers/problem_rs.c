#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *radix_sort(int n, int *arr, int ndigits) {
	int *output = calloc(n, sizeof(int));

    	int b[10] = {0};

    	int expn = 1;
    	for (int i = 0; i < ndigits; i++)
        	expn *= 10;

    	for (int i = 0; i < n; i++)
        	b[(arr[i] / expn) % 10]++;

    	for (int i = 1; i < 10; i++)
        	b[i] += b[i - 1];

    	for (int i = n - 1; i >= 0; i--) {
		int d = (arr[i] / expn) % 10; 
		output[b[d] - 1] = arr[i]; 
		b[d]--;
	}

    	return output;
}

int main() {
	int n, ndigits, i, res;
	int *arr, *answ;

	res = scanf("%d", &n);
	assert(res == 1);

	arr = calloc(n, sizeof(int));
	if (arr == NULL) {
		printf("Error allocation");
		abort();
	}
        for (i = 0; i < n; i++) {
                res = scanf("%d", &arr[i]);
                assert(res == 1);
        }
	
	res = scanf("%d", &ndigits);
	assert(res == 1);

	answ = radix_sort(n, arr, ndigits);

	for (i = 0; i < n; i++)
    		printf("%d ", answ[i]);

	free(arr);
	free(answ);

	return 0;
}
