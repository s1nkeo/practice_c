#include <stdio.h>
#include <assert.h>

void multiply(unsigned A[4], unsigned B[4], unsigned m) {
	unsigned tmp[4];

	tmp[0] = (A[0] * B[0] + A[1] * B[2]) % m;
	tmp[1] = (A[0] * B[1] + A[1] * B[3]) % m;
 	tmp[2] = (A[2] * B[0] + A[3] * B[2]) % m;
 	tmp[3] = (A[2] * B[1] + A[3] * B[3]) % m;

	A[0] = tmp[0];
	A[1] = tmp[1];
	A[2] = tmp[2];
	A[3] = tmp[3];

}

void pow_mod(unsigned A[4], unsigned n, unsigned m, unsigned result[4]) {
	unsigned mult[4] = {
		A[0] % m,
		A[1] % m,
		A[2] % m,
		A[3] % m
	};
	unsigned prod[4] = {1, 0, 0, 1};

	while (n > 0) {
		if ((n % 2) == 1) {
			multiply(prod, mult, m);
			n = n - 1;
		}
		multiply(mult, mult, m);
		n = n / 2;
	}
	result[0] = prod[0];
	result[1] = prod[1];
	result[2] = prod[2];
	result[3] = prod[3];
}

int main() {
	unsigned A[4];
	unsigned n, m, res;
	unsigned result[4];

	res = scanf("%u %u %u %u %u %u", &A[0], &A[1], &A[2], &A[3], &n, &m);
	assert(res == 6);

	pow_mod(A, n, m, result);

	printf("%u %u %u %u\n", result[0], result[1], result[2], result[3]);

	return 0;
}
