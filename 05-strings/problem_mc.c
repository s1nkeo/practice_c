#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min_coins(int sum, int *coin, int n) {
	int ans;
	int *v = malloc((sum + 1) * sizeof(int));

	if (v == NULL)
		return -1;

	v[0] = 0;
	
	for (int i = 1; i <= sum; i++)
		v[i] = INT_MAX;


    	for (int i = 1; i <= sum; i++) {
        	for (int j = 0; j < n; j++) {
            		if (i >= coin[j] && v[i - coin[j]] != INT_MAX) {
                		if (v[i] > v[i - coin[j]] + 1)
                    			v[i] = v[i - coin[j]] + 1;
            		}
        	}
    	}

    	ans = v[sum];
    	free(v);

    	return ans;
}

int main() {
	int sum, n, ans, res;
	int *coin;

	res = scanf("%d%d", &sum, &n);
	assert(res == 2);

	coin = malloc(n * sizeof(int));
	if (coin == NULL) {
		printf("Allocation error\n");
		abort();
	}

	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);

	ans = min_coins(sum, coin, n);

	printf("%d\n", ans);		

	free(coin);

	return 0;
}
