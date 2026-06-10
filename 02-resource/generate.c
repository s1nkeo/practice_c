#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int is_prime(long long n) {
    if (n < 2) return 0;
    for (long long j = 2; j * j <= n; ++j) {
        if ((n % j) == 0) {
            return 0;
        }
    }
    return 1;
}

int length(int a, int b) {
    int n = 0;

    while (1) {
        long long val = 1LL * n * n + 1LL * a * n + b;

        if (!is_prime(val))
            return n;

        n++;
    }
}

void search(int N) {
	int bestLen = 0;
    	int bestA = 0;
    	int bestB = 0;

    	for (int b = 2; b < N; b++) {
		if (!is_prime(b))
            		continue;

        	if (b == 2) {
			for (int a = -N + 1; a < N; a++) {
				if (!is_prime(1 + a + b))
                    			continue;

                		int len = length(a, b);

                		if (len > bestLen) {
                    			bestLen = len;
                    			bestA = a;
                    			bestB = b;
                		}
            		}

        	} else {
			int startA = -N + 1;

            		if ((startA & 1) == 0)
                		startA++;

            		for (int a = startA; a < N; a += 2) {
				if (!is_prime(1 + a + b))
                    			continue;

                		int len = length(a, b);

                		if (len > bestLen) {
                    			bestLen = len;
                    			bestA = a;
                    			bestB = b;
                		}
            		}
        	}
    	}
	printf("%d %d %d\n", bestA, bestB, bestLen);
}


int main() {
	int N, res;

	res = scanf("%d", &N);
	assert(res == 1);
	search(N);

	return 0;
}
