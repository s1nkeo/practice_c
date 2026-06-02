#include <stdio.h>

int print_converted(unsigned n, unsigned base) {
    int i = 0;
    unsigned arr[32];
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
    
    scanf("%u %u", &n, &base);
    print_converted(n, base);
           
    return 0;
}
