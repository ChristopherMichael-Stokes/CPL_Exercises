#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
#define TABSTOP 4

int getline(char s[], int lim);
void detab(int n, char line[], int *len);
void entab(int n, char line[], int *len);
void fold(int n, char line[], int len);

int main(int argc, char **argv)
{
	char line[MAXLINE];
	int linewidth = 50;
	if (argc > 1)
		linewidth = atoi(argv[1]);
	for (int len; (len = getline(line, MAXLINE)) > 0; ) {
		//detab(TABSTOP, line, &len);
		//entab(TABSTOP, line, &len);
		fold(linewidth, line, len);
		printf("%s\n", line);
	}
	return 0;	
}

void shift_down(int start, int gap, char line[], int len) 
{
	for (int i = start; i <= len; ++i) {
		line[i] = line[i + gap];
	}
}

/* simple fold */
void fold(int n, char line[], int len)
{
/*  look for a space, when found look at next word and if combined 
 *  length is greater than n, split at the position of the space.
 *  --> keep repeating until true, or there is no space before n
 *  if no space, put a hyphen at nth char and end line
 */
	int line_width = 1, line_begin = 0;
	for (int i = 0; i < len; ++i, ++line_width) {
		/* edge case if no spaces */
		if (line_width == n) {
			for (int j = len; j >= i; --j)
				line[j + 2] = line[j];
			
			len += 2;
			line[i] = '-';
			line[i + 1] = '\n';	
			line_width = 0;
			continue;
		}
		/* if a space is found, start finding words */
		if (' ' == line[i] || '\t' == line[i]) {
			int word_start, word_end = i, previous_space;
			while (word_end - line_begin < n) {
				previous_space = word_end;
				word_start = word_end + 1;
				/* start of word */
				while (word_start < len && 
					(' ' == line[word_start] ||
					 '\t' == line[word_start]))
					++word_start;

				word_end = word_start + 1;
				if (word_start - line_begin > n) {
					break;
				}

				/* end of word */
				while (word_end < len && 
					!(' ' == line[word_end] ||
					 '\t' == line[word_end]))
					++word_end;
			}
			i = previous_space;
			line[i] = '\n';
			shift_down(line_begin = word_start, word_start - i - 1,
					line, len -= (word_start - i));
			line_width = 0;

		}
	}
}
//void shift_down(int start, int gap, char line[], int len) 
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
