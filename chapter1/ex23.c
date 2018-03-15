#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int getline(char s[], int lim);
void strip_comments(char line[], int *len);

int main(void)
{
	char line[MAXLINE];
	for (int len; (len = getline(line, MAXLINE)) > 0; ) {

		printf("%s\n", line);
	}
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
