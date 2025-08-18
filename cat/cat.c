#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
	char buf[BUFSIZ];
	ssize_t n;
	int fd, i;

	if (argc == 1) {
		while ((n = read(STDIN_FILENO, buf, sizeof buf)) > 0)
			if (write(STDOUT_FILENO, buf, n) != n)
				return 1;
		return 0;
	}

	for (i = 1; i < argc; i++) {
		fd = open(argv[i], O_RDONLY);
		if (fd < 0) {
			fprintf(stderr, "cat: %s: %s\n", argv[i],
				strerror(errno));
			return 1;
		}
		while ((n = read(fd, buf, sizeof buf)) > 0)
			if (write(STDOUT_FILENO, buf, n) != n)
				return 1;
		close(fd);
	}
	return 0;
}
