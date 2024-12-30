#include <stdio.h>

int main(void)
{
  FILE *f = fopen("bin/hello.txt", "w");
  if (f == NULL) return -1;
  fprintf(f, "Hello\n");
  printf("Wrote to file\n");
  return 0;
}
