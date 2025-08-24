#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char ch;
	while (read(STDIN_FILENO, &ch, 1) > 0)
		putchar(toupper(ch));
	return EXIT_SUCCESS;
}
