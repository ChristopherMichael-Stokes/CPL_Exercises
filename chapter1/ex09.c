#include <stdio.h>

int main(void)
{
	int c, prev = getchar();
	if (prev == EOF)
		return 0;
	putchar(prev);
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (prev != ' ') {
				putchar(c);
			}
		} else {
			putchar(c);
		}
		prev = c;
	} 

	return 0;
}
