#include <stdio.h>

#define START 'a'
#define END 'z'
#define RANGE END-START

void print_horizontal(int a[]) 
{
	int i, j;
	for (i = 0; i <= RANGE; i++) { 
		printf("%c\t| ", i + START);		
		for (j = 0; j < a[i]; j++) {
			putchar('#');	
		}
		putchar('\n');
	}
	
}

int main(void) 
{
	int c, chars[RANGE + 2] = {0};

	while ((c = getchar()) != EOF) {
		if (c >= START && c <= END)
			chars[c - START]++;	
		else 	
			chars[RANGE + 1]++;
	}
	
	print_horizontal(chars);

	return 0;
}
