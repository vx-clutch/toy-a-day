#include <stdio.h>
#include <stdlib.h>

int a, b, c;

int main()
{
	fprintf(stderr, "a> "), fflush(stdout);
	scanf("%d", &a);
	fprintf(stderr, "b> "), fflush(stdout);
	scanf("%d", &b);
	fprintf(stderr, "c> "), fflush(stdout);
	scanf("%d", &c);

	if (a == b && a == c)
		puts("equilateral");
	else if (a == b || a == c)
		puts("isosceles");
	else
		puts("scalene");
	return EXIT_SUCCESS;
}
