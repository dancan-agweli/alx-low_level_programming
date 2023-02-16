#include <stdio.h>
/**
 * main - A program for type of 
 * Return: 0 (sucess)
 */
int main(void)
{
char a;
int b;
long int c;
long long int d;
float e;
printf("sizeof char:%lu byte(s)\n"(unsigned long)sizeof(a));
printf("sizeof int:%lu byte(s)\n"(unsigned long)sizeof(b));
printf("sizeof long int:%lu byte(s)\n"(unsigned long)sizeof(c));
printf("sizeof long long int:%lu byte(s)\n"(unsigned long)sizeof(d));
printf("sizeof float:%lu byte(s)\n"(unsigned long)sizeof(e));
return (0);
}
