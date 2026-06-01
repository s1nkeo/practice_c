#include <stdio.h>
#include <assert.h>

int main() {
    int x, y;
    int res;
    
    res = scanf("%d %d", &x, &y);
    assert(res == 2);
    
    while (y != 0) {
        printf("%d ", x/y);
        
        int temp = y;
        y = x % y;
        x = temp;
    }
    return 0;
}
