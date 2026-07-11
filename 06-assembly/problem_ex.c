#include <assert.h>
#include <stdio.h>
#include <string.h>

unsigned as_uint(float f) { 
    unsigned u;
	memcpy(&u, &f, sizeof(unsigned));
	return u;
}

float as_float(unsigned u) {
	float f;
	memcpy(&f, &u, sizeof(float));
	return f;  
}

int main() {
	float f;
	int res;

	res = scanf("%f", &f);
	assert(res == 1);

	unsigned u = as_uint(f);
	u ^= 0x2aaaaa;
	float new_f = as_float(u);
	printf("%.5f\n", new_f);

	return 0;
}
