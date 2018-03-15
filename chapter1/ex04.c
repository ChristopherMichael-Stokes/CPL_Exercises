#include <stdio.h>

int main(void)
{
	int celc;

	for (celc = 0; celc <= 100; celc += 10)
		printf("%3d %6.2f\n", celc, (celc*(9.0/5.0)+32.0));

	return 0;	
}
