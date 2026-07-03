#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int max_items(int capacity, int *w, int n) {
	int *v = calloc(capacity + 1, sizeof(int));
    		if (!v)
        		return -1;

    	for (int i = 0; i < n; i++) {
        	int weight = w[i];

        	for (int j = capacity; j >= weight; j--) {
            		if (v[j] < v[j - weight] + 1)
                		v[j] = v[j - weight] + 1;
        	}
    	}

    	int ans = v[capacity];
    	free(v);

    	return ans;
}

int *read_weights(int n) {
    	int *w = malloc(n * sizeof(int));
    	if (!w)
        	return NULL;

    	for (int i = 0; i < n; i++)
        	scanf("%d", &w[i]);

    	return w;
}

int main() {
	int capacity, n, res, ans;
	int *w;

	res = scanf("%d%d", &capacity, &n);
	assert(res == 2);

	w = read_weights(n);

	ans = max_items(capacity, w, n);

	printf("%d\n", ans);

    	free(w);

    	return 0;
}
