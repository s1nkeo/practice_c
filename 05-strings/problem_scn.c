#include <stdio.h>

int main() {
	char str;
	int res = 0;

	while (scanf("%c", &str) == 1)
		res += str;

	printf("%i", res);
	return 0;
}
