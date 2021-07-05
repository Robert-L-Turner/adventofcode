#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test(FILE *fp, int x, int right, int down, int divisor) {
  int trees = 0, row = 0;
  char buf[200];
  while (fgets(buf, sizeof(buf), fp) != NULL) {
    if (row % down == 0) {
      if (buf[x] == '#') {
        trees++;
      }
      x = (x + right) % divisor;
    }
    row++;
  }
  fseek(fp, 0, SEEK_SET);
  return trees;
}

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage : %s [inputfile]\n", argv[0]);
    exit(-1);
  }

  FILE *fp;
  if ((fp = fopen(argv[1], "r")) == NULL) {
    puts("Error reading file");
    exit(-1);
  }

  printf("Tree Count: %d %d %d %d %d Product: %ld\n", test(fp, 0, 1, 1, 31),
         test(fp, 0, 3, 1, 31), test(fp, 0, 5, 1, 31), test(fp, 0, 7, 1, 31),
         test(fp, 0, 1, 2, 31),
         ((long)test(fp, 0, 1, 1, 31) * test(fp, 0, 3, 1, 31) *
          test(fp, 0, 5, 1, 31) * test(fp, 0, 7, 1, 31) *
          test(fp, 0, 1, 2, 31)));

  fclose(fp);
  return 0;
}
