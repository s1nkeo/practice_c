#include <stdio.h>
#include <assert.h>

#if 0
int iabs(int x) {
    return (x < 0) ? -x : x;
}

int eu_mod (int x, int y) {
    int r;
    assert(y != 0);
    r = x % y;
    if (r < 0) r += iabs(y);
    return r;
}
#endif

long long egcd(long long x, long long y, long long *a, long long *b) {
    if (y == 0) {
        *a = 1;
        *b = 0;
        return x;
    }
    
    long long a1, b1;
    long long d = egcd(y, x % y, &a1, &b1);
    
    *a = b1;
    *b = a1 - (x / y) * b1;
    
    return d;
}

int main() {
    long long x, y, a, b;
    scanf("%lld %lld", &x, &y);
    
    long long d = egcd(x, y, &a, &b);
    
    if (d < 0) {
        d = -d;
        a = -a;
        b = -b;
    }
    
    printf("%lld %lld %lld", a, b, d);
    
     return 0;
}
