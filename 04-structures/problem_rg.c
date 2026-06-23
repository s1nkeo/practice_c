#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a, b, c, d;

int mygen(int num) {
  	return (a * num + b) % c + d;
}

typedef int (*generator_t)(int);

unsigned cycle_len(generator_t gen) {
	int fast = 0;
	int slow = 0;
        unsigned count = 1;

        do {
        	slow = gen(slow);
        	fast = gen(gen(fast));
    	} while (slow != fast);

    	int step = gen(slow);

    	while (step != slow) {
        	step = gen(step);
        	count++;
    	}
    	return count;
}

int main() {
  	int res = scanf("%d%d%d%d", &a, &b, &c, &d);
  	assert(res);
  	printf("%u\n", cycle_len(mygen));

	return 0;
}
