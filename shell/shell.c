#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cmd[BUFSIZ];
char prompt[BUFSIZ] = ">";

int main()
{
	while (true) {
		printf("%s ", prompt), fflush(stdout);
		if (fgets(cmd, sizeof cmd, stdin) != NULL) {
			size_t i = 0;
			while (cmd[i] != '\0') {
				if (cmd[i] == '\n') {
					cmd[i] = '\0';
					break;
				}
				++i;
			}
		}
		if (!strcmp("exit", cmd)) {
			puts("exit");
			break;
		}
		if (!strcmp("prompt", cmd)) {
			fgets(prompt, sizeof prompt, stdin);
			prompt[strcspn(prompt, "\n")] = 0;
			continue;
		}
		system(cmd);
	}
	return EXIT_SUCCESS;
}
