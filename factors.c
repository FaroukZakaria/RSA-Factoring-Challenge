#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		/*if (strlen(line) > 18)
			printf("PASS\n");*/
		num = strtoull(line, NULL, 10);
		if (num % 2 == 0)
			printf("%llu=%llu*2\n", num, num / 2);
		else
		{
			for (i = 3; i < num ** 0.5 + 1; i += 2)
			{
				if (num % i == 0)
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
