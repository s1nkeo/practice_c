#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct sieve_t {
	int n;
	unsigned char *mod1;
	unsigned char *mod5;
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
	unsigned max = sv->n * CHAR_BIT * 6;

    	sv->mod1[0] |= 1u << 0;

    	for (unsigned j = 5; j * j < max; j += 2) {
        	if (j % 6 != 1 && j % 6 != 5)
            		continue;

        	unsigned idx;
        	unsigned char *arr;

        	if (j % 6 == 1) {
            		idx = j / 6;
            		arr = sv->mod1;
        	} else {
            		idx = (j - 5) / 6;
            		arr = sv->mod5;
        	}

        	if (arr[idx / CHAR_BIT] & (1u << (idx % CHAR_BIT)))
            		continue;

        	for (unsigned k = j * j; k < max; k += j) {
			if (k % 6 == 1) {
                		unsigned ki = k / 6;
                		sv->mod1[ki / CHAR_BIT] |= (1u << (ki % CHAR_BIT));
            		} else if (k % 6 == 5) {
                		unsigned ki = (k - 5) / 6;
                		sv->mod5[ki / CHAR_BIT] |= (1u << (ki % CHAR_BIT));
            		}
        	}
    	}
}

int is_prime(struct sieve_t *sv, unsigned n) {
	unsigned idx;
	unsigned char *arr;

    	if (n == 2 || n == 3)
        	return 1;

    	if (n < 2)
        	return 0;

    	if (n % 6 != 1 && n % 6 != 5)
        	return 0;

    	if (n % 6 == 1) {
        	idx = n / 6;
        	arr = sv->mod1;
    	} else {
        	idx = (n - 5) / 6;
        	arr = sv->mod5;
    	}

    	return ((arr[idx / CHAR_BIT] >> (idx % CHAR_BIT)) & 1) == 0;
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
    	s->n = ((sieve_bound(n) / CHAR_BIT) / 6) + 1;
    	s->mod1 = (unsigned char *) calloc(s->n, sizeof(char));
    	s->mod5 = (unsigned char *) calloc(s->n, sizeof(char));

    	fill_sieve(s);

    	outp = nth_prime(s, n);
    	printf("%d\n", outp);

    	free(s->mod1);
    	free(s->mod5);
    	free(s);
}
