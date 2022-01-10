#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_input(void) {
  FILE *fp;
  if ((fp = fopen("input3", "r")) == NULL) {
    puts("Error reading file\n");
    exit(-1);
  }

  fseek(fp, 0, SEEK_END);
  int filesize = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  char *input;

  input = (char *)malloc(sizeof(char) * (filesize + 1));
  if (input == NULL) {
    puts("Malloc failed\n");
    exit(-1);
  }

  fread(input, filesize, 1, fp);
  input[filesize] = '\0';
  fclose(fp);
  return input;
}

void part_one(char *input) {
  int bitcount = 0;
  char *ptr = input;
  while (*ptr != '\n') {
    bitcount++;
    ptr++;
  }
  if (bitcount == 0) {
    puts("Invalid input format, must not start with '\n'");
    exit(-1);
  }

  int *most_common_bit = (int *)calloc(bitcount, sizeof(int));
  if (most_common_bit == NULL) {
    puts("Malloc failed\n");
    exit(-1);
  }

  for (ptr = input; *ptr != '\0'; ptr++) {
    int i = 0;
    while (*ptr != '\n') {
      if (i >= bitcount) {
        puts("Input line malformed: line length varies");
        exit(-1);
      }
      most_common_bit[i++] += *(ptr++) == '1' ? 1 : -1;
    }
  }

  int gamma = 0, epsilon = 0;
  for (int i = bitcount - 1, j = 0; i >= 0; --i, j++) {
    gamma |= (most_common_bit[j] > 0 ? 1 : 0) << i;
    epsilon |= (most_common_bit[j] > 0 ? 0 : 1) << i;
  }

  printf("Part One: %d\n", gamma * epsilon);
  free(most_common_bit);
}

void part_two(char *input) {
  char *buffer = malloc(strlen(input)+1 * sizeof(char));
  char *o2_filter= malloc(strlen(input)+1 * sizeof(char));
  char *co2_filter= malloc(strlen(input)+1 * sizeof(char));
  if (buffer == NULL || o2_filter == NULL || co2_filter == NULL) {
    puts("Malloc failed");
    exit(-1);
  }
  strcpy(buffer, "");
  strcpy(o2_filter, input);
  strcpy(co2_filter, input); 
  
  int bitcount = 0;
  char *ptr = input;
  while (*ptr != '\n') {
    bitcount++;
    ptr++;
  }
  if (bitcount == 0) {
    puts("Invalid input format, must not start with '\n'");
    exit(-1);
  }

  int *most_common_bit = (int *)calloc(bitcount, sizeof(int));
  if (most_common_bit == NULL) {
    puts("Malloc failed\n");
    exit(-1);
  }
  int o2 = 0, co2 = 0;
  
  int bit = 0;
  while (strlen(o2_filter) >= bitcount + 2) {
    for (ptr = o2_filter; *ptr != '\0'; ptr++) {
      most_common_bit[bit] += *(ptr + bit) == '1' ? 1 : -1;
      while (*ptr != '\n' && *ptr !='\0') {
        ptr++;
      }
    }
    ptr = o2_filter;
    while (*ptr != '\0') {
      if (most_common_bit[bit] >= 0 && *(ptr+bit) == '1') {
        strncat(buffer, ptr, bitcount+1);
      }
      else if (most_common_bit[bit] < 0 && *(ptr+bit) == '0') {
        strncat(buffer, ptr, bitcount+1);
      }
      if (*(ptr + bitcount) == '\0') {
        break;
      }
      ptr += bitcount + 1;
    }
    strcpy(o2_filter, buffer);
    strcpy(buffer, "");  
    bit++;
  }
  
  free(most_common_bit);
  most_common_bit = (int *)calloc(bitcount, sizeof(int));
  if (most_common_bit == NULL) {
    puts("Malloc failed\n");
    exit(-1);
  }
  
  bit = 0;
  while (strlen(co2_filter) >= bitcount + 2) {
    for (ptr = co2_filter; *ptr != '\0'; ptr++) {
      most_common_bit[bit] += *(ptr + bit) == '1' ? 1 : -1;
      while (*ptr != '\n' && *ptr !='\0') {
        ptr++;
      }
    }
    ptr = co2_filter;
    while (*ptr != '\0') {
      if (most_common_bit[bit] >= 0 && *(ptr+bit) == '0') {
        strncat(buffer, ptr, bitcount+1);
      }
      else if (most_common_bit[bit] < 0 && *(ptr+bit) == '1') {
        strncat(buffer, ptr, bitcount+1);
      }
      if (*(ptr + bitcount) == '\0') {
        break;
      }
      ptr += bitcount + 1;
    }
    strcpy(co2_filter, buffer);
    strcpy(buffer, "");  
    bit++;
  }
  
  for (ptr = o2_filter, bit = 0; bit < bitcount; bit++) {
    o2 |= (*(ptr+bit) == '1' ? 1 : 0) << (bitcount - 1 - bit);
  }
  for (ptr = co2_filter, bit = 0; bit < bitcount; bit++) {
    co2 |= (*(ptr+bit) == '1' ? 1 : 0) << (bitcount - 1 - bit);
  }

  printf("Part Two: %d\n", o2*co2);  
  free(buffer);
  free(o2_filter);
  free(co2_filter);
  free(most_common_bit);
}

int main(void) {
  char *input = read_input();
  part_one(input);
  part_two(input);

  // Clean Up
  free(input);
}
