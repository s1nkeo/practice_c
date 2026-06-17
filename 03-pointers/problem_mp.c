#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Poly {
	unsigned n;
	unsigned *p;
};

struct Poly mult(struct Poly lhs, struct Poly rhs) {
	struct Poly ret = { rhs.n + lhs.n - 1, NULL };
	ret.p = calloc(ret.n, sizeof(unsigned));
	
	for (int i = 0; i < lhs.n; i++) {
		for (int j = 0; j < rhs.n; j++) {
			ret.p[i + j] += lhs.p[i] * rhs.p[j];
		}
	}
	
	return ret;
}

int main() {
	int res;
	struct Poly lhs, rhs;
	
	res = scanf("%u %u", &lhs.n, &rhs.n);
	assert(res == 2);

	lhs.p = calloc(lhs.n, sizeof(unsigned));
	if (lhs.p == NULL) {
		printf("Allocation error");
		abort();
	}

	for (int i = 0; i < lhs.n; i++) {
                scanf("%u", &lhs.p[i]);
        }

	rhs.p = calloc(rhs.n, sizeof(unsigned));
        if (rhs.p == NULL) {
                printf("Allocation error");
                abort();
        }

	for (int i = 0; i < rhs.n; i++) {
                scanf("%u", &rhs.p[i]);
        }
	
	struct Poly ret = mult(lhs, rhs);
	
	int last = ret.n - 1;
    	while (last > 0 && ret.p[last] == 0) 
        	last--;
	
	for (int k = 0; k <= last; k++)
		printf("%u ", ret.p[k]);
	printf("\n");

	free(lhs.p);
	free(rhs.p);
	free(ret.p);

	return 0;
}
