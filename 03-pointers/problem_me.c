#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int majority_element(const int *parr, int len) {
	int candidate;
	int count = 0;
	
	for (int i = 0; i < len; i++) {
		if (count == 0) {
			candidate = parr[i];
			count = 1;
		} else if (parr[i] == candidate) {
			count++;
		} else {
			count--;
		}
	}

	count = 0;

	for (int i = 0; i < len; i++) {
		if (parr[i] == candidate)
			count++;
	}
	
	if (count > (len / 2))
		return candidate;
		
	return -1;	
}

int main() {
	int res, n, i, answ;
  	int *arr;

  	res = scanf("%d", &n);
  	assert(res == 1);
  	assert(n > 0);

  	arr = calloc(n, sizeof(int));
  	for (i = 0; i < n; ++i) {
    		res = scanf("%d", arr + i);
    		assert(res == 1);
  	}

  	answ = majority_element(arr, n);

  	printf("%d\n", answ);

  	free(arr);
  	return 0;
}
