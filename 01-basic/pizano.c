#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned long long fib_mod(unsigned long long n, unsigned m) {
    unsigned long long first = 0ull, second = 1ull; int idx;
    unsigned long long tmp;
    if (n == 0) return 0ull;
    for (idx = 2; idx <= n; ++idx) {
        tmp = second;
        second = ((second % m) + (first % m)) % m;
        first = tmp;
    }
    return second;
}

int get_pisano_period(long long m) {
    long long first = 0, second = 1, tmp; int idx = 0;
    do {
        tmp = second;
        second = (first + second) % m;
        first = tmp;
        idx++;
    } while ((first != 0) || (second != 1));
    return idx;
}

int main() {
    long long x, m, fib;
    int res;

    res = scanf("%lld%lld", &x, &m);
    assert(res == 2);
    res = get_pisano_period(m);
    printf("%lld %d\n", fib_mod(x % res, m), res);
    return 0;
}

