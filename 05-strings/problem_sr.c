#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char *str, int len) {
	for (int i = 0; i < len; i++)
		printf("%c", str[i]);
}

void reverse(char *str, int len) {
	for (int i = 0; i < len / 2; i++) {
		char a;

		a = str[len - 1 - i];
		str[len - 1 - i] = str[i];
		str[i] = a;
	}
}

int read_str(char **str, int *len) {
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
	int len1, len2;
	char *str1;
	char *str2;
	char *last;
	int res = 0;

	res = read_str(&str2, &len2);
	assert(res == 1);

	res = read_str(&str1, &len1);
	assert(res == 1);

	last = str1;
	
	while ((last = strstr(last, str2)) != NULL) {
		reverse(last, len2);

		last += len2;
	}

	print_str(str1, len1);

	free(str2);
	free(str1);

	return 0;
}
