#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct triple {
  int x, y, z;
};

int tcmp(void const *key, void const *elt) {
  struct triple const *lhs = (struct triple const *)key;
  struct triple const *rhs = (struct triple const *)elt;
  if (lhs->x == rhs->x && lhs->y == rhs->y)
    return (lhs->z < rhs->z);
  if (lhs->x == rhs->x)
    return (lhs->y < rhs->y);
  return (lhs->x < rhs->x);
}

typedef int (*cmp_t)(const void *lhs, const void *rhs);

static void memswap(void *a, void *b, int size) {
    unsigned char *pa = a;
    unsigned char *pb = b;

    for (int i = 0; i < size; ++i) {
        unsigned char tmp = pa[i];
        pa[i] = pb[i];
        pb[i] = tmp;
    }
}

int selstep(void *parr, int eltsize, int numelts, int nsorted, cmp_t cmp) {
    char *arr = parr;

    int min_pos = nsorted;

    for (int i = nsorted + 1; i < numelts; ++i) {
        void *cur = arr + i * eltsize;
        void *min = arr + min_pos * eltsize;

        if (cmp(cur, min))
            min_pos = i;
    }

    memswap(arr + nsorted * eltsize,
            arr + min_pos * eltsize,
            eltsize);

    return 0;
}

int main() {
  int i, res, n, last;
  struct triple *parr;

  res = scanf("%d", &n);
  assert(res == 1);
  assert(n > 2);

  parr = (struct triple *)calloc(n / 3, sizeof(struct triple));

  for (i = 0; i < n / 3; ++i) {
    res = scanf("%d %d %d", &parr[i].x, &parr[i].y, &parr[i].z);
    assert(res == 3);
  }

  res = scanf("%d", &last);
  assert(res == 1);
  assert(last < n);

  selstep(parr, sizeof(struct triple), n / 3, last / 3, &tcmp);

  for (i = 0; i < n / 3; ++i)
    printf("%d %d %d\n", parr[i].x, parr[i].y, parr[i].z);

  free(parr);
  return 0;
}
