#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sieve(unsigned n) {
	int res = 0;

	if (n < 2) return 0;

	char *s = malloc((n + 1) * sizeof(char));
	if (s == NULL) {
		printf("Allocation error");
		abort();
	}

	for (int i = 0; i <= n; i++) {
		s[i] = 0;
	}
	
	s[0] = s[1] = 1;

	for (unsigned j = 2; j * j <= n; j++) {
		if (!s[j]) {
			for(unsigned k = j * j; k <= n; k += j) {
				s[k] = 1;
			}
		}
	}
	
	for(unsigned i = 2; i <= n; i++) {
		if (!s[i])
			res++;
	}

	free(s);

	return res;
}

int main() {
	unsigned n;
       	int result;

	result = scanf("%u", &n);
	assert(result == 1);

	printf("%d\n", sieve(n));

	return 0;
}


	
