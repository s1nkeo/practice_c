#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

unsigned long long pow_mod(unsigned long long n, unsigned long long k, unsigned long long m) {
	unsigned long long mult = n % m;
	unsigned long long prod = 1;
	while (k > 0) {
		if ((k % 2) == 1) {
			prod = (prod * mult) % m;
			k = k - 1;
		}
		mult = (mult * mult) % m;
		k = k / 2;
	}
	return prod;
}

int fermat(unsigned long long p) {
	if (p < 2)
        	return 0;
    	if (p == 2 || p == 3)
        	return 1;
    	if (p % 2 == 0)
        	return 0;
	for (int i = 0; i < 10; i++) {
		unsigned long long a = 2 + rand() % (p - 3);

		if (pow_mod(a, p - 1, p) != 1)
            		return 0;
	}
	
	return 1;
}

int main() {
	unsigned long long p;
	int res;

	res = scanf("%llu", &p);
	assert(res == 1);

	srand(time(NULL));

	printf("%d\n", fermat(p));

	return 0;
}
