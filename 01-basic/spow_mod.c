#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned pow_mod(unsigned n, unsigned long long k, unsigned m) {
    unsigned mult = n % m;
    unsigned prod = 1;
    while (k > 0) {
        if (k % 2 == 1) {
            prod = (prod * mult) % m;
            k = k - 1;
        }
        mult = (mult * mult) % m;
        k = k / 2;
    }
    return prod;
}

unsigned spow_mod(unsigned n, unsigned long long k, unsigned m) {
    unsigned long long exp = n;

    for (unsigned i = 2; i < k; i++) {
        unsigned long long p = 1;

	for (unsigned long long j = 0; j < exp; j++) {
		p = p * n;
	}
	exp = p;
    }
    return pow_mod(n, exp, m);
}

int main() {
    int a, b, c;
    int res;
    unsigned long long stepen;
    res = scanf("%d%d%d", &a, &b, &c);
    assert(res == 3);
    
    printf("%d\n", spow_mod(a, b, c));
    return 0;
}

