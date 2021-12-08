#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp;
  if ((fp = fopen("input2", "r")) == NULL) {
    puts("Error reading file\n");
    exit(-1);
  }
  
  char command[1000][10];
  char buf[10];
  int value[1000];
  int buf2;

  int i=0;
  while (fscanf(fp, "%s %d", buf, &buf2) != EOF) {
    if (i>=2000){
      puts("Error - buffer exceeded - file too large");
      break;
    }
    strcpy(command[i], buf);
    value[i++] = buf2;
  }
  
  // Stop comparing at last entry in file
  int horizontal=0;
  int depth=0;

  for (int j=0; j<i; j++){
    if (strcmp(command[j], "forward") == 0) {
      horizontal += value[j];
    }
    else if (strcmp(command[j], "down") == 0) {
      depth += value[j];
    }
    else if (strcmp(command[j], "up") == 0) {
      depth -= value[j];
    }
  }
  printf("Count for part one: %d\n", horizontal*depth);
  
  horizontal=0;
  depth=0;
  int aim=0;

  for (int j=0; j<i; j++){
    if (strcmp(command[j], "forward") == 0) {
      horizontal += value[j];
      depth += aim * value[j];
    }
    else if (strcmp(command[j], "down") == 0) {
      aim += value[j];
    }
    else if (strcmp(command[j], "up") == 0) {
      aim -= value[j];
    }
  }
  printf("Count for part two: %d\n", horizontal*depth);
  return 0;
}
