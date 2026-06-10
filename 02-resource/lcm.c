#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

long long iabs(long long x) {
    return (x < 0) ? -x : x;
}

long long gcd(long long x, long long y) {
     	long long temp;
	while (y != 0) {
        	temp = y;
        	y = x % y;
        	x = temp;
    }
    return iabs(x);
}

long long lcm(long long x, long long y) {
	return (x * y) / gcd(x, y);
}

#if 0
long long lcm(int n) {
	long long result = 2;

	if (n < 2)
		abort();
	
	for (int i = 2; 2 <= n; i++) {
		result = (result * i) / gcd(result, i);
	}
	return result;
}
#endif

int main() {
	int N, res;
	long long ans = 1;

	res = scanf("%d", &N);
	assert(res == 1);

	for (int i = 2; i <= N; i++) {
		ans = lcm(ans, i);
	}
	printf("%lld\n", ans);

	return 0;
}
	
