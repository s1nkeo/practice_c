#include <stdio.h>
#include <assert.h>

int is_prime(unsigned n) {
    if (n < 2) return 0;
    for (int j = 2; j * j <= n; ++j) {
        if ((n % j) == 0) {
            return 0;
        }
    }       
    return 1;
}

int prime(unsigned n) {
	if (n == 0) return 0;

	int number = 2;
	int count = 0;

	while (count <= n) {
	 	if (is_prime(number) == 1) {
			count++;
			if (count == n) {
				return number;
			}
		}
		number++;
	}
	return number;
}

int main() {
	int n, res;

	res = scanf("%d", &n);
	assert(res == 1);
	printf("%d\n", prime(n));

	return 0;
}


