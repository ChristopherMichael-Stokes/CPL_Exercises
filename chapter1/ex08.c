#include <stdio.h>

#define BLANK 0
#define TAB 1
#define NEWLINE 2

int main(void)
{
	unsigned int counts[] = {0,0,0};
	int c;

	printf("Type something: \n");
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			counts[BLANK]++;
		else if (c == '\t')
			counts[TAB]++;
		else if (c == '\n')
			counts[NEWLINE]++;
	}

	printf("Amount of blanks: %d\nAmount of tabs: %d\nAmount of new lines: %d\n",
			counts[BLANK], counts[TAB], counts[NEWLINE]);
	return 0;
}
