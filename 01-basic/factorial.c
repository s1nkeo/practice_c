#include <stdio.h>
#include <assert.h>

int factorial(int n) {
	int fact = 1;
	int i = 1;

	while (i <= n) {
		fact *= i;
		i++;
	}
	return fact;
}

int system_fact(int n) {
	int i;

	while (factorial(i) <= n)
		i++;
	i--;

	while (i >= 1) {
		int fact = factorial(i);

		printf("%d.", n / fact);

		n = n % fact;

		i--;
	}
}

int main() {
	int n;

	int res = scanf("%d", &n);
	assert(res == 1);
	assert(n > 0);

	system_fact(n);

	return 0; 
}
