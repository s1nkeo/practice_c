#include <stdio.h>
#include <assert.h>

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

int gcd(int x, int y) {
    int temp;
    while (y != 0) {
        temp = y;
        y = eu_mod(x, y);
        x = temp;
    }
    return iabs(x);
}

int main() {
	int x = 0, y = 0, g;
	int res;
  
	res = scanf("%d %d", &x, &y);
	assert(res == 2);
	g = gcd(x, y);
	printf("%d\n", g);
	return 0;
}
