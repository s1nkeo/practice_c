#include <stdio.h>
#include <assert.h>

long long egcd(long long x, long long y, long long *coef_x, long long *coef_y) {
	long long old_r = x, r = y;
	long long old_a = 1, a = 0;
	long long old_b = 0, b = 1;

	while (r != 0) {
		long long q = old_r / r;
		
		long long tmp;
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

int main() {
	long long x, y, a, b, d;

	int res = scanf("%lld %lld", &x, &y);
	assert(res == 2);
    
	d = egcd(x, y, &a, &b);
	assert(d == a * x + b * y);
    
	printf("%lld %lld %lld", a, b, d);
    
	return 0;
}
