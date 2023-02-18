#include <stdio.h>

/**
 * main - Aprogram for  alphabets both in upper and lower
 * Return: always 0
 */
int main(void)
{
	int lowerc;
	int upperc;

	for (lowerc = 'a'; lowerc <= 'z'; lowerc++)
		putchar (lowerc);
	putchar ('\n');
	for (upperc = 'A'; upperc <= 'Z'; upperc++)
		putchar (upperc);
	putchar ('\n');
	return (0);
}
