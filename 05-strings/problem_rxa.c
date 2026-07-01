#include <stdio.h>
#include <stdlib.h>

char nextsym() {
	int c = getchar();
	if (c == EOF)
		return '\0';
	return c;
}

int automaton() {
	int state = 1;

	for (;;) {
		char c = nextsym();
		
		switch (c) {
    			case 'a':
        			switch (state) {
        				case 1: state = 1; break;
        				case 2: state = 1; break;
       					case 3: state = 5; break;
        				case 4: state = 5; break;
        				case 5: state = 5; break;
        			}
        			break;

    			case 'b':
        			switch (state) {
        				case 1: state = 2; break;
        				case 2: state = 2; break;
        				case 3: state = 3; break;
        				case 4: state = 4; break;
        				case 5: state = 5; break;
        			}
        			break;

    			case 'c':
        			switch (state) {
        				case 1: state = 5; break;
        				case 2: state = 3; break;
        				case 3: state = 4; break;
        				case 4: state = 3; break;
        				case 5: state = 5; break;
        			}
        			break;

    			default:
        			return (state == 2 || state == 3 || state == 4);
   	 	}
	}	
}

int main() {
	int res = automaton();
	printf("%d\n", res);
	return 0;

}
