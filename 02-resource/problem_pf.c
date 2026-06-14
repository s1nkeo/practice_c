#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

unsigned long long mul_mod(unsigned long long a, unsigned long long b, unsigned long long m) {
        return (unsigned long long)((__int128)a * b % m);
}

unsigned long long pow_mod(unsigned long long n, unsigned long long k, unsigned long long m) {
        unsigned long long mult = n % m;
        unsigned long long prod = 1;
        while (k > 0) {
                if ((k % 2) == 1)
                        prod = mul_mod(prod, mult, m);
                        
                mult = mul_mod(mult, mult, m);
                k = k / 2;
        }
        return prod;
}

int is_prime_small(unsigned long long n) {
        if (n < 2)
                return 0;

        for (unsigned long long i = 2; i * i <= n; i++) {
                if (n % i == 0)
                        return 0;
        }

        return 1;
}

int fermat(unsigned long long p) {
        if (p < 2)
                return 0;

        if (p == 2 || p == 3)
                return 1;

        if (p % 2 == 0)
                return 0;

        if (p < 1000000)
                return is_prime_small(p);

        for (int i = 0; i < 20; i++) {
                unsigned long long a = 2 + rand() % 1000000;

                if (a >= p)
                        a = 2;

                if (pow_mod(a, p - 1, p) != 1)
                        return 0;
        }

        return 1;
}

unsigned long long seq(unsigned long long k, unsigned long long n) {
        unsigned long long LIMIT = (1ULL << 60) - 1;
        unsigned long long first = 0;
        unsigned long long second = 1;
        unsigned long long answer = 0;

        while (1) {
                if (fermat(second))
                        answer = second;

                __int128 next =
                        (__int128)k * second +
                        (__int128)n * first;

                if (next > LIMIT)
                        break;

                first = second;
                second = (unsigned long long)next;
        }

        return answer;
}

int main() {
        unsigned long long k;
        unsigned long long n;

        int res = scanf("%llu %llu", &k, &n);
        assert(res == 2);

        srand((unsigned)time(NULL));

        printf("%llu\n", seq(k, n));

        return 0;
}

#if 0
unsigned long long seq(unsigned long long k, unsigned long long n) {
	unsigned long long LIMIT = (1ULL << 60) - 1;
        unsigned long long first = 0;
        unsigned long long second = 1;
        unsigned long long answer, third;

	while (1) {
                if (fermat(second))
                        answer = second;

                third = k * second + n * first;

                if (third > LIMIT)
                        break;

                first = second;
                second = third;
        }
	return answer;

}

int main() {
	unsigned long long k, n;
	int res;

	res = scanf("%llu %llu", &k, &n);
	assert(res == 2);
        printf("%llu\n", seq(k, n));

        return 0;
}
#endif
