#include <stdio.h>
#define MAXLINE 1000
#define SHORT 80 

int getline(char s[], int lim);

int main(void)
{
	char line[MAXLINE];
	for (int len; (len = getline(line, MAXLINE)) > 0; ) {
		printf("%d\n",len);
		if (len > SHORT) {
			printf("%s", line);
		}
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


