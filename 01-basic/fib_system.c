#include <stdio.h>
#include <assert.h>

unsigned fib_arr[32] = {0};

unsigned fill_fib_arr(unsigned x) {
	int i;

	fib_arr[0] = 1; 	// fib(2)
	fib_arr[1] = 2; 	// fib(3)
	
	i = 2;
	while (fib_arr[i - 1] <= x) {
		fib_arr[i] = fib_arr[i - 1] + fib_arr[i - 2];
		i++;
	}
	return i;
}

unsigned print_fib_system(unsigned x) {
	int count = fill_fib_arr(x);

	for (int i = count - 2; i >= 0; i--) {
		if (fib_arr[i] <= x) {
			printf("1");
			x = x - fib_arr[i];
		} else {
			printf("0");
		}
	}
}

int main() {
	unsigned x, res;

	res = scanf("%u", &x);
	assert(res == 1);

	print_fib_system(x);

	return 0;
}
