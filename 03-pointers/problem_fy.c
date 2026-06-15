#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int myrand() {
	static unsigned long int seed = 1;
	seed = seed * 1103515245 + 12345;
  	return (unsigned int)(seed / 65536) % 32768;
}

int *fisher_yates(int arr[], unsigned len) {
	int i, n, tmp;

	for (i = len - 1; i > 0; i--) {
		n = myrand() % (i + 1);
		
		tmp = arr[i];
		arr[i] = arr[n];
		arr[n] = tmp;
	}
	return arr;
}

int main() {
        unsigned len;
        int *arr;
        int res;

        res = scanf("%u", &len);
        assert(res == 1);

	if (len == 0) {
		printf("0\n");
		return 0;
	}

        arr = malloc(len * sizeof(int));
        assert(arr != NULL);

        for (int i = 0; i < len; i++) {
                scanf("%d", &arr[i]);
        }
	
	fisher_yates(arr, len);
        for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}	

        free(arr);

        return 0;
}

