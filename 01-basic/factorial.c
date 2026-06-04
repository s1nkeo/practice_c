#include <stdio.h>
#include <assert.h>

int factorial(int n) {
	int fact = 1;

	while (n > 1) {
		fact *= n;
		n--;
	}
	return fact;
}

void system_fact(int n) {
	int i = 1;

	while (factorial(i) <= n)
		i++;
	i--;
	
	int fact = factorial(i);

	while (i >= 1) {

		printf("%d.", n / fact);

		n = n % fact;
		
		fact = fact / i;

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
