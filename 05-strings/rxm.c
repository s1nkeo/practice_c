#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

void reverse(char *s, int len) {
    	for (int i = 0; i < len / 2; i++) {
        	char t = s[i];
        	s[i] = s[len - i - 1];
        	s[len - i - 1] = t;
    	}
}

void reverse_matches(char *text, regex_t *reg) {
    	regmatch_t match;
    	char *cur = text;

    	while (regexec(reg, cur, 1, &match, 0) == 0) {
		if (match.rm_so == match.rm_eo) {
            		if (*cur == '\0')
                		break;
            		cur++;
            		continue;
        	}

		reverse(cur + match.rm_so, match.rm_eo - match.rm_so);
		cur += match.rm_eo;
    	}
}

int read_str(char **str, int *len) {
        char a;
        int res;

        res = scanf("%d", len);
        assert(res == 1);

        *str = calloc(*len + 1, sizeof(char));
        if (*str == NULL) {
                printf("Allocation error\n");
                return 0;
        }

        scanf("%*c");

        for (int i = 0; i < *len; i++) {
                res = scanf("%c", &(*str)[i]);
                assert(res == 1);
        }
        (*str)[*len] = '\0';

        return 1;
}

int main() {
	char *pattern;
    	char *text;
    	int len1, len2;

    	read_str(&pattern, &len1);
    	read_str(&text, &len2);

    	regex_t reg;

    	int err = regcomp(&reg, pattern, REG_EXTENDED);
	if (err != 0) {
    		char buf[256];
    		regerror(err, &reg, buf, sizeof(buf));
    		fprintf(stderr, "%s\n", buf);

    		free(pattern);
    		free(text);
    		return 1;
	}

    	reverse_matches(text, &reg);

    	puts(text);

    	regfree(&reg);

    	free(pattern);
    	free(text);

	return 0;
}
