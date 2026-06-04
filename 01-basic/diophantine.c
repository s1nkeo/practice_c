#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int egcd(int x, int y, int *coef_x, int *coef_y) {
        int old_r = x, r = y;
        int old_a = 1, a = 0;
        int old_b = 0, b = 1;

        while (r != 0) {
                int q = old_r / r;

                int tmp;
                tmp = r;
                r = old_r - q * r;
                old_r = tmp;

                tmp = a;
                a = old_a - q * a;
                old_a = tmp;

                tmp = b;
                b = old_b - q * b;
                old_b = tmp;
        }

        if (old_r < 0) {
                old_r = -old_r;
                old_a = -old_a;
                old_b = -old_b;
        }

        *coef_x = old_a;
        *coef_y = old_b;

        return old_r;
}

int diophantine(int a, int b, int c, int *x, int *y) {
	int d;
        d = egcd(a, b, x, y);
	
	if ((c % d) != 0) {
		return 0;
	}

	*x *= c / d;
	*y *= c / d;

	return 1;	
}

int main() {
	int a, b, c, x, y;
	int res;
	
	res = scanf("%lld %lld %lld", &a, &b, &c);
	assert(res == 3);
	
	if (diophantine(a, b, c, &x, &y)) {
		printf("%d %d\n", x, y);
	} else {
		printf("NONE\n");
	}

	return 0;
}


