#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int is_prime(int n) {
	if (n < 2) return 0;
	for (int j = 2; j * j <= n; ++j) {
		if ((n % j) == 0) {
			return 0;
		}
	}
	return 1;
}

int rotate(int n, int digits) {
	int p = 1;
	int first, rest;

	for (int i = 1; i < digits; i++) {
		p = p *10;
	}

	first = n / p;
	rest = n % p;

	return rest * 10 + first;
}

int is_circular_prime(int n) {
	int temp = n;
	int digits = 0;

	while (temp > 0) {
        	digits++;
        	temp /= 10;
    	}

    	temp = n;

    	for (int i = 0; i < digits; i++) {
        	if (is_prime(temp) == 0)
            		return 0;

        	temp = rotate(temp, digits);
    	}
    	return 1;
}

int closest_circular_prime(int N) {
    	int offset = 0;

    	while (1) {
		int down = N - offset;

        	if (down > 1 && is_circular_prime(down))
            		return down;

        	int up = N + offset;

        	if (is_circular_prime(up))
            		return up;

        offset++;
    }
}

int main() {
	int N, res;

	res = scanf("%d", &N);
	assert(res == 1);
	printf("%d\n", closest_circular_prime(N));

	return 0;
}

	
