#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 4

int getline(char s[], int lim);
void detab(int n, char line[], int *len);
void entab(int n, char line[], int *len);

int main(void)
{
	char line[MAXLINE];
	for (int len; (len = getline(line, MAXLINE)) > 0; ) {
		//detab(TABSTOP, line, &len);
		entab(TABSTOP, line, &len);
		printf("%s\n", line);
	}
	return 0;	
}

void entab(int n, char line[], int *len) 
{
	int spaces = 0, gap = n - 1;
	for (int i = 0; i < *len; ++i) {
		if (' ' == line[i]) ++spaces;
		else spaces = 0;
		if (spaces == n) {
			line[i - gap] = '\t';
			for (int j = i + 1; j <= *len; ++j) {
				line[j - gap] = line[j];	
			}
			i -= gap;
			*len -= gap;	
			spaces = 0;
		}
	}	
}

void detab(int n, char line[], int *len) 
{
	for (int i = 0; i < *len; ++i) {
		if ('\t' == line[i]) {
			for (int j = *len; j >= i; j--) {
				line[j+n] = line[j];
				line[j] = '@';
			}	
			for (int j = i; j <= i + n; j++) {
				line[j] = ' ';
			}	
			*len += n;
			i += n;
		}
	}
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
