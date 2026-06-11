#include <stdio.h>
#include <assert.h>

void converted (unsigned n) {
	int i = 0;
	int lsb = 0;
	int msb;
	unsigned arr[32];
	
	if (n == 0) {
		printf("-1\n");
		return;
	}

	while (n > 0) {
		arr[i] = n % 2;
		n = n / 2;
		i++;
	}

	msb = i - 1;
	
	for (int j = 0; j < i; j++) {
		if (arr[j] == 1) {
			lsb = j;
			break;
		}
	}		
	printf("%d %d\n", msb, lsb);
}

int main() {
	unsigned n;
	int res;

	res = scanf("%u", &n);
	assert(res == 1);
	converted(n);

	return 0;
}



