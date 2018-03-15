#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
	char line[MAXLINE], longest[MAXLINE];
	int max = 0;
	for (int len; (len = getline(line, MAXLINE)) > 0; ) {
		printf("line: %s\tlength: %d\n", line, len);
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}	

	if (max > 0)
		printf("longest line is: %s\t with %d characters\n",
				longest, max);
	return 0;
}

int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i  < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	for (int i = 0; (to[i] = from[i]) != '\0'; ++i);
}
