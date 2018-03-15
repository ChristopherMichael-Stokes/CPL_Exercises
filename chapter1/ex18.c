#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int getline(char s[], int lim);
void stripline(char source[], int len);

int main(void)
{
	char line[MAXLINE];
	for (int len; (len = getline(line, MAXLINE)) > 0; ) {
		stripline(line, len);
		printf("(start)%s(end)\n", line);
	}
	return 0;
}

void stripline(char source[], int len)
{
	int i, j;
	char swap[len];
	for (i = 0; source[i] == ' ' || source[i] == '\t'; ++i)
		if ('\0' == source[i])
			continue;
	for (j = len - 1; source[j] == ' ' || source[j] == '\t' || source[j] == '\n'; --j);
	int length_new = j - i + 1;
	for (int inc = 0; inc < length_new; ++inc)
		swap[inc] = source[inc + i];
	swap[length_new] = '\0';
	for (int inc = 0; inc < length_new; ++inc)
		source[inc] = swap[inc];
	source[length_new] = '\0';	
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
