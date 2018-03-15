#include <stdio.h>

#define MAX 15

void print_horizontal(int a[]) {
	int i, j;
	printf("\tFrequencies\n");
	for (i = 0; i <= MAX; i++) {
		printf("%d\t|", i + 1);
		for (j = 0; j < a[i]; j++) {
			printf("#");	
		}	
		printf("\n");
	}
}

void print_vertical(int a[]) {
	int i, j, max_index = 0, max_value, copy[MAX+1];

	copy[0] = a[0];
	for (i = 1; i <= MAX; i++) {
		copy[i] = a[i];
		if (a[i] > a[max_index]) {
			max_index = i;
		}	
	}

	max_value = a[max_index];
	for (i = 0; i <= MAX; i++) {
		copy[i] -= max_value;	
		printf("%d\n",copy[i]);
	}

	for (i = 0; i < max_value; i++) {
		for (j = 0; j <= MAX; j++) {
			if (copy[j] < 0) {
				printf("   ");
				copy[j]++;
			} else {
				printf("#  ");
			}	
		}	
		putchar('\n');
	}	
	for (i = 0; i <= MAX * 3; i++) 
		putchar('_');
	putchar('\n');
	for (i = 0; i <= MAX; i++) {
		if (i < 9) 
			printf("%d  ",i+1);	
		else 
			printf("%d ",i+1);	
	}
	putchar('\n');		
}


int main(void)
{
	int c, char_count = 0, boundaries[MAX+1] = {0}, i;

	typedef enum {IN, OUT} states;
	states state = OUT;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				if (char_count > MAX)
					boundaries[MAX]++;
				else
					boundaries[char_count-1]++;	
				char_count = 0;
			}
		} else if (state == OUT) {
			state = IN;
			char_count++;
		} else {
			char_count++;
		}	
	}
	printf("Frequencies:\n");
	for (i = 0; i <= MAX; i++) 
		printf("%d: %d\t", i+1, boundaries[i]);

	print_horizontal(boundaries);	
	printf("\n\n");
	print_vertical(boundaries);

	return 0;
}
