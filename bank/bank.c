#include <stdio.h>
#include <stdlib.h>

const char *store = "secure.data";
char buffer[BUFSIZ];
int a, b, account;

int main()
{
	FILE *fp = fopen(store, "r");
	if (!fp) {
		perror("");
		return EXIT_FAILURE;
	}

	fgets(buffer, BUFSIZ, fp);
	account = atoi(buffer);
	fclose(fp);
	fp = fopen(store, "w");

	while (true) {
		printf("Fantastik Minibanken!\n\n  1. Balance\n  2. Withdrawl\n  3. Deposit\n  4. Leave\n\n");
		printf("*");
		scanf("%d", &a);
		switch (a) {
		case 1:
			printf("$%d\n", account);
			break;
		case 2:
			scanf("%d", &b);
			account -= b;
			break;
		case 3:
			scanf("%d", &b);
			account += b;
			break;
		case 4:
			goto cleanup;
		default:
			fputs("?\n", stdout);
			break;
		}
	}

cleanup:
	fprintf(fp, "%d", account);
	return EXIT_SUCCESS;
}
