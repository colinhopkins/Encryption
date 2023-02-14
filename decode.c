#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{

	srand(time(0)); // Use the current time as the seed for random generator

	if (argc != 2)
	{
		fprintf(stderr, "Please invoke as %s <key>\n", argv[0]);
		return 1; // Indicate something went wrong
	}
	char *key=argv[1];
	int nextChar = getchar();
	while (nextChar != EOF)
	{
		/* TODO:
			Using the key, write an encoded character to standard out
			For example, if you encode nextChar and save it in variable enCoded,
			You can use: putchar(enCoded);
		*/
		nextChar = getchar();
	}
	return 0; // Indicate nothing went wrong
}
