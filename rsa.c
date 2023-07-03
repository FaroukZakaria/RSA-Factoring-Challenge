#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ch_prime(unsigned long long int n);
/**
 * main - Entry point
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *file;
	char line[256];
	unsigned long long int num, i;

	if (argc != 2)
	{
		printf("usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: File not found\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		num = strtoull(line, NULL, 10);
		if ((num % 2 == 0) && ch_prime(num / 2) == 0)
			printf("%llu=%llu*2\n", num, num / 2);
		else
		{
			for (i = 3; i * i <= num; i += 2)
			{
				if ((num % i == 0) && ch_prime(num / i) == 0)
				{
					printf("%llu=%llu*%llu\n", num, num / i, i);
					break;
				}
			}
		}
	}
	fclose(file);
	return (0);
}
/**
 * ch_prime - checks prime
 * @n: number
 * Return: ...
 */
int ch_prime(unsigned long long int n)
{
	unsigned long long int i;

	if (n < 2)
		return (1);
	for (i = 2; i * i <= n; i++)
		if (n % i == 0)
			return (1);
	return (0);
}
