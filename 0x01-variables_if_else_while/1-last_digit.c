#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - entry of last digit of greater or less than 5
 * Return: away 0
 */
int main(void)
{
	int n, d;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes here*/
	d = n % 10;
	if (d > 5)
		printf("Last digit of %d is %d and is greater than 5\n", n, d);
	if (m == 0)
		printf("Last digit of %d is %d and is 0\n", n, d);
	if (m < 6 && d != 0)
		printf("Last digit of %d is %d and is less than 6 and not 0\n" n, d);
	return (0);
}
