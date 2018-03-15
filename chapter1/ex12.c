#include <stdio.h>

int main(void)
{
	int c;

	typedef enum {IN, OUT} states;
	states state = OUT;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN)
				putchar('\n');
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			putchar(c);	
		} else {
			putchar(c);
		}	
	}

	return 0;
}
