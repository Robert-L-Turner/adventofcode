#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp;
  if ((fp = fopen("input3", "r")) == NULL) {
    puts("Error reading file\n");
    exit(-1);
  }

  fseek(fp, 0, SEEK_END);
  int filesize = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  char *input;
  int *most_common_bit, bitcount, i, j, gamma=0, epsilon=0;
  
  input = (char *)malloc(sizeof(char) * (filesize + 1));
  if (input == NULL) {
    puts("Malloc failed\n");
    exit(-1);
  }

  fread(input, filesize, 1, fp);
  input[filesize] = '\0';

  char *ptr = input;
  for (bitcount = 0; *ptr != '\n'; bitcount++, ptr++);
  if (bitcount == 0) {
    puts("Invalid input format, must not start with '\n'");
    exit(-1);
  }

  //Part One
  //
  most_common_bit = (int *)calloc(bitcount, sizeof(int));
  if (most_common_bit == NULL) {
    puts("Malloc failed\n");
    exit(-1);
  }

  for (ptr = input; *ptr != '\0'; ptr++) {
    int i = 0;
    while (*ptr != '\n') {
      most_common_bit[i++] += *(ptr++) == '1' ? 1 : -1;
    }
  }

  for (i = bitcount - 1, j = 0; i >= 0; --i, j++) {
    gamma |= (most_common_bit[j] > 0 ? 1 : 0) << i;
    epsilon |= (most_common_bit[j] > 0 ? 0 : 1) << i;
  }

  printf("Part One: %d\n", gamma * epsilon);

  // Part Two

  // Clean Up
  free(input);
  free(most_common_bit);
}
