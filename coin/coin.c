#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));
  if (rand() % 2)
    puts("Heads");
  else
    puts("Tails");
  return 0;
}
