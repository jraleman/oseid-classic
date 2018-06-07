#include <stdio.h>


#define CHAR_ASCIITILDE 126
#define CHAR_SPACE 32
#define FALSE 1
#define PSO_NAME_SIZE_MAX 12
#define PSO_NAME_SIZE_MIN 1

const char* TOO_FEW_ARGS = "Sorry, too few arguments. Everyone has a name, right ?";
const char* TOO_MANY_ARGS = "Sorry, too many arguments. \"Kireek SucksBalls\" is not a valid PSO Name !";
const char* NAME_TOO_SHORT = "Sorry, Name is empty. Please input some seccy err... sexy Name next time !";
const char* NAME_TOO_LONG = "Sorry, Name must contain 12 characters tops !";
const char* NAME_NOT_ASCII = "Sorry, Name contains non-ASCII character(s), those are the worst!";

char* pso_sectionid[] = { "Pinkal", "Redria", "Oran", "Yellowboze", "Whitill", "Viridia", "Greenill", "Skyly", "Bluefull", "Purplenum" };

unsigned int my_strlen(char *str)
{
	char* c = str;
	while (*c)
	{
		c++;
	}
	return (c - str);
}

unsigned int is_ascii(char* str)
{
	while (*str) 
	{
		if ((*str < CHAR_SPACE) || (*str > CHAR_ASCIITILDE))
		{
			return 1;
		}
		str++;
	}
	return 0;
}

unsigned int pso_sum(char* input_str, unsigned int cval)
{
	unsigned int sum = 0;
	char *c = input_str;
	while (*c)
	{
		sum += (*c);
		c++;
	}
	return ((sum + cval) % 10);
}

char *sectionid(char *str)
{
	const int pso_value = 5;
	return pso_sectionid[pso_sum(str, pso_value)];
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		puts(TOO_FEW_ARGS);
		return 1;
	}
	if (argc > 2)
	{
		puts(TOO_MANY_ARGS);
		return 1;
	}
	if (my_strlen(argv[1]) < PSO_NAME_SIZE_MIN)
	{
		puts(NAME_TOO_SHORT);
		return 1;
	}
	if (my_strlen(argv[1]) > PSO_NAME_SIZE_MAX)
	{
		puts(NAME_TOO_LONG);
		return 1;
	}
	if (is_ascii(argv[1]) == FALSE)
	{
		puts(NAME_NOT_ASCII);
		return 1;
	}
	puts(sectionid(argv[1])); 
}