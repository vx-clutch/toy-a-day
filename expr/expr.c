#include <stdio.h>
#include <stdlib.h>

typedef enum {
	ADD,
	SUB,
	MUL,
	DIV,
} operator_t;

int r, lhs, rhs;
char c;
operator_t opt;

int main()
{
	while (true) {
		printf("*"), fflush(stdout);
		c = getchar();
		switch (c) {
		case '+':
			opt = ADD;
			goto done;
		case '-':
			opt = SUB;
			goto done;
		case '*':
			opt = MUL;
			goto done;
		case '/':
			opt = DIV;
			goto done;
		default:
			fputs("Invalid operator\n", stderr);
		}
	}
done:
	scanf("%d", &lhs);
	scanf("%d", &rhs);

	switch (opt) {
	case ADD:
		r = lhs + rhs;
		break;
	case SUB:
		r = lhs - rhs;
		break;
	case MUL:
		r = lhs * rhs;
		break;
	case DIV:
		r = lhs / rhs;
		break;
	}

	printf("%d\n", r);
	return EXIT_SUCCESS;
}
