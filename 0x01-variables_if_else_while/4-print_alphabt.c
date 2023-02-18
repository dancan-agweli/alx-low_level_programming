#include <stdio.h>

/**
 * main - A program to print alphabet except q and e
 * Return: 0 always
 */
int main(void)
{
	char alp;

	for (alp = 'a'; alp <= 'z'; alp++)
	{
		if (alp != 'e' && alp != 'q')
			putchar (alp);
	}
	putchar ('\n');
	return (0);
}
