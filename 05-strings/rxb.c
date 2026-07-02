#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *pattern = "^[A-Za-z0-9.]+@[A-Za-z]+\\.[A-Za-z]+$";

int main() {
	regex_t regex;
	int status;
	char email[256];

	status = regcomp(&regex, pattern, REG_EXTENDED);
	if (status != 0)
		return 1;

	while (fgets(email, sizeof(email), stdin)) {
        	size_t len = strlen(email);
        	if (len > 0 && email[len - 1] == '\n') {
            		email[len - 1] = '\0';
        	}

        	int match_status = regexec(&regex, email, 0, NULL, 0);

        	if (match_status == 0) {
            		printf("1\n");
        	} else {
           		printf("0\n");
        	}
    	}

    	regfree(&regex);

    	return 0;
}
