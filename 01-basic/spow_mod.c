#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned pow_mod(unsigned n, unsigned long long stepen, unsigned modul) {
    unsigned mult = n % modul;
    unsigned prod = 1;
    while (stepen > 0) {
        if ((stepen % 2) == 1) {
            prod = (prod * mult) % modul;
            stepen = stepen - 1;
        }
        mult = (mult * mult) % modul;
        stepen = stepen / 2;
    }
    return prod;
}

unsigned spow_mod(unsigned n, unsigned long long s_stepen, unsigned modul) {
    unsigned idx = 1;
    unsigned stepen = n;
    for(; idx < s_stepen; idx++) {
        n = pow_mod(n, stepen, modul);
    }
    return n;
}

int main(void) {
    int a, b, c;
    int res;
    unsigned long long stepen;
    res = scanf("%d%d%d", &a, &b, &c);
    assert(res == 3);
    
    printf("%d\n", spow_mod(a, b, c));
    return 0;
}

