#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
	long long int num, i;

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
		if (strlen(num) > 18) //do python command here!!
		num = atoll(line);
		if (num % 2 == 0)
			printf("%lld=%lld*2\n", num, num / 2);
		else
		{
			for (i = 3; i < (int)sqrt(num) + 1; i += 2)
			{
				if (num % i == 0)
				{
					printf("%lld=%lld*%lld\n", num, num / i, i);
					break;
				}
			}
		}
	}
	fclose(file);
	return (0);
}
