#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <fenv.h>

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

void unpack_float(unsigned u, unsigned *exp, unsigned *mant) {
	*mant = u & 0x7FFFFF;
	*exp = (u >> 23) & 0xFF;
}

unsigned get_rounded(float a, float b, int rounding_mode) {
	fesetround(rounding_mode);
	float fres = a / b;
	unsigned ures = as_uint(fres);
	return ures;
}

void print_parts(unsigned exp, unsigned mant) {
	printf("0x%x 0x%x", exp, mant);	
}

int main() {
	float a, b;
	int res;

	res = scanf("%f %f", &a, &b);
	assert(res == 2);
	
	unsigned u_down = get_rounded(a, b, FE_DOWNWARD);
    unsigned u_up = get_rounded(a, b, FE_UPWARD);
    
    unsigned exp_down = 0, mant_down = 0;
    unsigned exp_up = 0, mant_up = 0;

    if (u_down == u_up) {
        unpack_float(u_down, &exp_down, &mant_down);
        print_parts(exp_down, mant_down);
    }
    else {
        unpack_float(u_down, &exp_down, &mant_down);
        unpack_float(u_up, &exp_up, &mant_up);
        
        print_parts(exp_down, mant_down);
        printf(" ");
        print_parts(exp_up, mant_up);
    }
    
	printf("\n");
    return 0;
}
