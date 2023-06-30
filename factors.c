#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <Python.h>
/**
 * exec - executes python code
 * @arg: argument
 * Return: Success if executed
 */
int exec(const char *arg)
{
	PyObject *pModule = NULL;
	PyObject *pFunc = NULL;
	PyObject *pArg = NULL;
	PyObject *pResult = NULL;
	int success = 0;

	Py_initialize();
	pModule = PyImport_ImportModule("pyfactors");
	if (pModule == NULL)
	{
		PyErr_Print();
		goto cleanup;
	}
	pFunc = PyObject_GetAttrString(pModule, "do_prime");
	if (pFunc == NULL || !PyCallable_Check(pFunc))
	{
		if (PyErr_Occurred())
			PyErr_Print();
		fprintf(stderr, "Cannot find function '%s'\n", "do_prime");
		goto cleanup;
	}
	pArg = Py_BuildValue("(s)", argument);
	if (pArg == NULL)
	{
		PyErr_Print();
		goto cleanup;
	}
	success = 1;
cleanup:
	Py_XDECREF(pResult);
	Py_XDECREF(pArg);
	Py_XDECREF(pFunc);
	Py_XDECREF(pModule);
	Py_Finalize();
	return (success);
}
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
		if (strlen(line) > 18)
			exec(line);
		num = strtoull(line, NULL, 10);
		if (num % 2 == 0)
			printf("%llu=%llu*2\n", num, num / 2);
		else
		{
			for (i = 3; i < (unsigned long long int)sqrt(num) + 1; i += 2)
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
