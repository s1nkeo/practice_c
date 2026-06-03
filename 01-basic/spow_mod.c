#include <stdio.h>

unsigned spow_mod(unsigned n, unsigned k, unsigned m) {
	unsigned mult = n % m;
	unsigned i = 1;

	while (i < k) {
		unsigned prod = 1;
		unsigned j = 0;

		while (j < mult) {
			prod = (prod * n) % m;
			j++;
		}

		mult = prod;
		i++;
	}
	return mult;
}

int main() {
	unsigned n, k, m;

	scanf("%u %u %u", &n, &k, &m);
	printf("%u\n", spow_mod(n, k, m));

	return 0;
}
