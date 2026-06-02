#include <stdio.h>

int print_converted(unsigned n, unsigned base) {
    int res = 0;
    int mult = 1;
    unsigned arr[];
    while (n >= base) {
        n = n / base;
        
        for (int i = 0; i <= ; i++) {
            arr[i] = n % base;
        }
        
        for (int j = sizeof(arr - 1); i >= 0; i--) {
            res += arr[j] * mult;
            mult *= 10;
        }
        return res;
    }
    
int main() {
    unsigned int n, base;
    
    scanf("%ud %ud", &n, &base);
    printf("%d", print_converted(n, base);
           
    return 0;
}
