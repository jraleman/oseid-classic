#include <stdio.h>
#include <string.h>

#define CHAR_ASCIITILDE 126
#define CHAR_SPACE 32
#define FALSE 1
#define PSO_NAME_SIZE_MAX 12
#define PSO_NAME_SIZE_MIN 1

const char* TOO_FEW_ARGS = "Sorry, too few arguments. Everyone has a name, right ?\n";
const char* TOO_MANY_ARGS = "Sorry, too many arguments. \"Kireek SucksBalls\" is not a valid PSO Name !\n";
const char* NAME_TOO_SHORT = "Sorry, Name is empty. Please input some seccy err... sexy Name next time !\n";
const char* NAME_TOO_LONG = "Sorry, Name must contain 12 characters tops !\n";
const char* NAME_NOT_ASCII = "Sorry, Name contains non-ASCII character(s), those are the worst!\n";

char* pso_sectionid[] = { "Pinkal", "Redria", "Oran", "Yellowboze", "Whitill", "Viridia", "Greenill", "Skyly", "Bluefull", "Purplenum" };

unsigned int is_ascii(char* str)
{
	char* c = str;
	while (*c) 
	{
		if ((*c < CHAR_SPACE) || (*c > CHAR_ASCIITILDE))
		{
			return 1;
		}
		c++;
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
		printf(TOO_FEW_ARGS);
		return 1;
	}
	if (argc > 2)
	{
		printf(TOO_MANY_ARGS);
		return 1;
	}
	if (strlen(argv[1]) < PSO_NAME_SIZE_MIN)
	{
		printf(NAME_TOO_SHORT);
		return 1;
	}
	if (strlen(argv[1]) > PSO_NAME_SIZE_MAX)
	{
		printf(NAME_TOO_LONG);
		return 1;
	}
	if (is_ascii(argv[1]) == FALSE)
	{
		printf(NAME_NOT_ASCII);
		return 1;
	}
	
	char *result = sectionid(argv[1]);
	if (strcmp(result, "Pinkal") == 0)
		printf("\033[1;35mPinkal\n\033[0m");
	else if (strcmp(result, "Redria") == 0)
		printf("\033[0;31mRedria\n\033[0m");
	else if (strcmp(result, "Oran") == 0)
		printf("\033[0;33mOran\n\033[0m");
	else if (strcmp(result, "Yellowboze") == 0)
		printf("\033[1;33mYellowboze\n\033[0m");
	else if (strcmp(result, "Whitill") == 0)
		printf("Whitill\n");
	else if (strcmp(result, "Viridia") == 0)
		printf("\033[0;32mViridia\n\033[0m");
	else if (strcmp(result, "Greenill") == 0)
		printf("\033[1;32mGreenill\n\033[0m");
	else if (strcmp(result, "Skyly") == 0)
		printf("\033[1;36mSkyly\n\033[0m");
	else if (strcmp(result, "Bluefull") == 0)
		printf("\033[0;34mBluefull\n\033[0m");
	else if (strcmp(result, "Purplenum") == 0)
		printf("\033[0;35mPurplenum\n\033[0m");
}