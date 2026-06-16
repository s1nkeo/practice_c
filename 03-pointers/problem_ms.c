#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *arr, int l, int m, int r) {
	int tmp[r - l + 1];
    	int i = l;
    	int j = m + 1;
    	int k = 0;
    	while (i <= m && j <= r) {
        	if (arr[i] <= arr[j]) {
            		tmp[k++] = arr[i++];
        	} else {
            		tmp[k++] = arr[j++];
        	}
    	}
    	while (i <= m) {
    		tmp[k++] = arr[i++];
    	}
    	while (j <= r) {
    		tmp[k++] = arr[j++];
    	}	
    	for (int t = 0; t < k; t++) {
    		arr[l + t] = tmp[t];
    	}
}

void merge_sort_imp(int *arr, int l, int r) {
  int m;
  if (l >= r)
    return;
  m = (l + r) / 2;
  merge_sort_imp(arr, l, m);
  merge_sort_imp(arr, m + 1, r);
  merge(arr, l, m, r);
}

int main() {
  int res, n, i;
  int *parr;

  res = scanf("%d", &n);
  assert(res == 1);
  assert(n > 0);

  parr = calloc(n, sizeof(int));

  for (i = 0; i < n; ++i) {
    res = scanf("%d", parr + i);
    assert(res == 1);
  }

  merge_sort_imp(parr, 0, n - 1);

  for (i = 0; i < n; ++i)
    printf("%d ", parr[i]);
  printf("\n");

  free(parr);
}
