#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <limits.h>

struct sieve_t {
	int n;
	unsigned char *s;
};

int sieve_bound(int num) {
    	double dnum, dres;
    	if (num <= 20 * CHAR_BIT)
        	return 100 * CHAR_BIT;
    	dnum = num;
    	dres = dnum * (log(dnum) + log(log(dnum)));
    	return (int) round(dres) + 1;
}

void fill_sieve(struct sieve_t *sv) {
	unsigned max = sv->n * CHAR_BIT;
	
	sv->s[0] = sv->s[0] | (1 << 0);
	sv->s[0] = sv->s[0] | (1 << 1);
	
	for (unsigned k = 4; k < max; k += 2) {
        	sv->s[k / CHAR_BIT] |= (1 << (k % CHAR_BIT));
    	}

    
    	for (unsigned j = 3; j * j < max; j += 2) {
        	if (((sv->s[j / CHAR_BIT] >> (j % CHAR_BIT)) & 1) == 0) {
            		for (unsigned k = j * j; k < max; k += 2 * j) {
				sv->s[k / CHAR_BIT] |= (1 << (k % CHAR_BIT));
            }
        }
    }
}

int is_prime(struct sieve_t *sv, unsigned n) {
	if (n >= (unsigned)sv->n * CHAR_BIT)
        	return 0;

	return ((sv->s[n / CHAR_BIT] >> (n % CHAR_BIT)) & 1) == 0;
}

int nth_prime(struct sieve_t *s, int N) {
	int cnt, p;
    	if (N == 1)
        	return 2;
    	if (N == 2)
        	return 3;

    	cnt = 2;
    	p = 5;

    	for (; ; ) {
        	if (is_prime(s, p)) {
            		cnt += 1;
            		if (cnt == N)
                		break;
        	}
        	p += 2;
        	if (is_prime(s, p)) {
            		cnt += 1;
            		if (cnt == N)
                		break;
        	}
        	p += 4;
    }

    return p;
}

int main() {
	int n, outp;
	int res;
	struct sieve_t *s;

    	res = scanf("%d", &n);
    	assert(res == 1);

    	s = (struct sieve_t *) malloc(sizeof(struct sieve_t));
    	assert(s);

    	s->n = (sieve_bound(n) / CHAR_BIT) + CHAR_BIT;
    	s->s = (char *) calloc(s->n, sizeof(char));
    	assert(s->s);

    	fill_sieve(s);
    	for (int i = 2; i < n; ++i)
      	printf("%d %d\n", i, is_prime(s, i));

    	outp = nth_prime(s, n);
    	printf("%d\n", outp);

    	free(s->s);
    	free(s);
}
