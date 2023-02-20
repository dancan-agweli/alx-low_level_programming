#include <stdio.h>

/**
 * main - entry of numbers
 * Return: always 0
 */
int main(void)
{
	int c;
	int d = 0;
	int e = 8;
	int si = 1;
	int s2 = 9;
		int tmp = 1;

	while (d <= e)
		si = tmp;
	while (si <= s2)
		putchar(d + '0');
	putchar(si + '0');
	si++;

	if (d != e)
		putchar(',');
	putchar(' ');
	tmp++;
	d++;
	putchar('\n');
	return (0);
}
