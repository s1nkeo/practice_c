#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

struct sieve_t {
    	int n;
    	char *s;
};

int sieve_bound(int num) {
    	double dnum, dres;
    	if (num <= 20)
        	return 100;
    	dnum = num;
    	dres = dnum * (log(dnum) + log(log(dnum)));
    	return (int) round(dres);
}

void fill_sieve(struct sieve_t *sv) {
	sv->s[0] = sv->s[1] = 1;

	for (unsigned j = 2; j * j <= sv->n; j++) {
		if (!sv->s[j]) {
			for(unsigned k = j * j; k <= sv->n; k += j) {
				sv->s[k] = 1;
			}
		}
	}
}

int nth_prime(struct sieve_t *sv, int N) {
	int result;
	int count = 0;

	for(unsigned i = 2; i <= sv->n; i++) {
		if (sv->s[i] == 0) {
			count++;
			if (count == N) {
				return i;
			}
		}
	}
	return -1;
		
}

int main() {
    	int n, outp;
   	int res;
    	struct sieve_t *s;

    	res = scanf("%d", &n);
    	assert(res == 1);
    	s = (struct sieve_t *) malloc(sizeof(struct sieve_t));
    	s->n = sieve_bound(n);
    	s->s = (char *) calloc(s->n + 1, sizeof(char));

    	fill_sieve(s);
    	outp = nth_prime(s, n);
    	printf("%d\n", outp);

    	free(s->s);
	free(s);
}
