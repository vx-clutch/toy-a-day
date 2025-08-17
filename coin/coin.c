#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
  if (argc < 2 || !argv[1]) return 1;
  srand(time(NULL));
  for (int i = 0; i < atoi(argv[1]); ++i) {
    if (rand() % 2)
      puts("Heads");
    else
      puts("Tails");
  }
  return 0;
}
