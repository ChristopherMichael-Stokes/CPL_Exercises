#include <stdio.h>

int main(void)
{
	int fahr;
	
	printf("Farenheit to Celcius\n");
	for (fahr = 0; fahr <= 300; fahr += 20) 
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	return 0;
}
