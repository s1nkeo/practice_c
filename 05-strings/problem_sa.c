#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcat_r(char *dest, const char *src, int *bufsz) {
	int lend = strlen(dest);
	int lens = strlen(src);
	int need = lend + lens + 1;
	char *new = NULL;

	if (need > *bufsz) {
		new = realloc(dest, need);

		if (new == NULL) {
			printf("failed reallocation\n");
			abort();
		}

		dest = new;
		*bufsz = need;
	}
	strcat(dest, src);

	return dest;
}

int main() {
  	int buflen, res, catlen;
  	char *buf, *catbuf;

  	res = scanf("%d", &buflen);
  	assert(res == 1);

  	buf = (char *)calloc(buflen + 1, sizeof(char));
  	assert(buf != NULL);

  	catlen = 10;
  	catbuf = (char *)calloc(catlen, sizeof(char));
  	assert(catbuf != NULL);

	for (; ; ) {
    		res = scanf("%s", buf);
    		if (res != 1)
      		break;
    		catbuf = strcat_r(catbuf, buf, &catlen);
  	}

	printf("%s\n", catbuf);
	free(buf);
	free(catbuf);
}
