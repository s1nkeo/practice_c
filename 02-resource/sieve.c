#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sieve(unsigned n) {
	int res = 0;

	char *s = malloc(n * sizeof(char));
	if (s == NULL) {
		printf("Allocation error");
		abort();
	}

	for (int i = 0; i <= n; i++) {
		s[i] = 0;
	}
	
	s[0] = s[1] = 1;

	for (int j = 2; j * j <= n; j++) {
		if (s[j] == 0) {
			for(int k = j * j; k <= n; k += j) {
				s[k] = 1;
			}
		}
	}
	
	for(int i = 2; i <= n; i++) {
		if (s[i] == 0)
			res++;
	}

	free(s);

	return res;
}

int main() {
	int n, result;

	result = scanf("%d", &n);
	assert(result == 1);

	printf("%d\n", sieve(n));

	return 0;
}


	
