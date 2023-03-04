#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long hash(unsigned char *str)
{
	unsigned long hash = 5381;
	int c;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return hash;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Please invoke as %s <key>\n", argv[0]);
		return 1;
	}

	char *key = argv[1];
	unsigned long shift = hash(key);
	int next_char = getchar();
	while (next_char != EOF)
	{
		if (next_char >= 'A' && next_char <= 'Z')
		{
			next_char += 'a' - 'A';
		}
		if ((next_char >= 'a' && next_char <= 'z') || (next_char >= '0' && next_char <= '9'))
		{
			int encoded_char = (next_char - 'a' + shift) % 26 + 'a';
			putchar(encoded_char);
		}
		else if (next_char == ' ' || next_char == '\t' || next_char == '\n')
		{
			putchar(next_char);
		}
		else
		{
			putchar(next_char);
		}
		next_char = getchar();
	}

	return 0;
}
