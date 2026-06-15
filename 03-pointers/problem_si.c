#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int moveright(int *arr, int key, int last) {
	int pos = last;
	while (pos > 0 && arr[pos - 1] > key) {
		arr[pos] = arr[pos - 1];
		pos--;
	}
	return pos;
}

void inssort(int *arr, int len) {
	int i;
  	for (i = 0; i < len; ++i) {
    		int key, pos;
    		key = arr[i];
    		pos = moveright(arr, key, i);
    		arr[pos] = key;
  	}
}

int main() {
	int res, answ, n, last, i;
  	int *parr;

  	res = scanf("%d", &n);
  	assert(res == 1);
  	assert(n > 0);

  	parr = calloc(n, sizeof(int));

  	for (i = 0; i < n; ++i) {
    		res = scanf("%d", parr + i);
    		assert(res == 1);
  	}

  	res = scanf("%d", &last);
  	assert(res == 1);
  	assert(last < n);
  
  	answ = moveright(parr, parr[last], last);

  	for (i = 0; i < n; ++i)
    		printf("%d ", parr[i]);
  	printf("\n");
  	printf("%d\n", answ);
  	free(parr);

	return 0;
}
