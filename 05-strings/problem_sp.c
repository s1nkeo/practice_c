#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_replace(const char *str, const char *from) {
	int count = 0;
	int len = strlen(from);

	if (len == 0)
		return 0;

	for (const char *p = str; (p = strstr(p, from)) != NULL; p += len)
		count++;

	return count;
}

char *replace(char *str, char const *from, char const *to) {
	int len_str = strlen(str);
	int len_from = strlen(from);
	int len_to = strlen(to);
	int new_size = 0;

	if (len_from == 0)
        	return strdup(str);

	int count = count_replace(str, from);

	new_size = len_str + count * (len_to - len_from) + 1;

	char *res = malloc(new_size);
	if (!res)
		return NULL;
	
	char *out = res;
    	char *pos = str;

    	while (*pos) {
        	char *match = strstr(pos, from);

        	if (match == pos) {
            		memcpy(out, to, len_to);
            		out += len_to;
            		pos += len_from;
        	} else {
            		*out++ = *pos++;
        	}
    	}
	*out = '\0';

	return res;
}

static char *read_word(int *len) {
  char *text;
  int res, n, i;

  res = scanf("%d", len);
  assert(res == 1);

  n = *len;
  assert(n > 0);

  text = (char *)calloc(n + 1, sizeof(char));
  assert(text != NULL);

  scanf("%*c");

  for (i = 0; i < n; ++i) {
    res = scanf("%c", text + i);
    assert(res == 1);
  }

  return text;
}

int main() {
  int i, nword, nrepl, nstr, res;
  char *word, *repl, *str, *newstr;

  word = read_word(&nword);
  repl = read_word(&nrepl);
  str = read_word(&nstr);

  newstr = replace(str, word, repl);

  printf("%s\n", newstr);

  free(word);
  free(repl);
  free(str);
  free(newstr);
}
