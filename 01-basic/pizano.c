#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int get_pisano_period(unsigned m) {
	unsigned first = 0;
	unsigned second = 1;
	unsigned tmp;
	unsigned period = 0;

	assert(m > 0);

	do {
			tmp = second;
			second = (first + second) % m;
			first = tmp;
			period++;
	} while (!(first == 0 && second == 1));
	return period;
}

int fib_mod(unsigned long long n, unsigned m) {
	unsigned long long first = 0ull, second = 1ull;
        int idx;

	assert(m > 0);

	if (m == 1) 
		return 0;

	n = n % get_pisano_period(m);

        if (n == 0)
                return 0ull;

        for (idx = 2; idx <= n; ++idx) {
                unsigned long long tmp = second;
                second = (second + first) % m;
                first = tmp;
        }
        return second;
}

int main() {
	unsigned n, m;
        int res;

        res = scanf("%u %u", &n, &m);
        if (res != 2) {
                printf("%s\n", "Wrong input");
                abort();
        }
        printf("%u %u\n", fib_mod(n, m), get_pisano_period(m));

        return 0;
}
