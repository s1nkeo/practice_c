#include <stdio.h>
#include <assert.h>

int print_converted(unsigned n, unsigned base) {
    int i = 0;
    unsigned arr[32];

    assert(base > 1 && base < 11);

    while (n > 0) {
        arr[i] = n % base;
        n = n / base;
        i++;
    }  
        for (int j = i - 1; j >= 0; j--) {
            printf("%u", arr[j]);
        }
     return 0;
}
    
int main() {
    unsigned n, base;
    int res;

    res = scanf("%u %u", &n, &base);
    assert(res == 2);
    print_converted(n, base);
           
    return 0;
}
