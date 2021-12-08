#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  if ((fp = fopen("input1", "r")) == NULL) {
    puts("Error reading file\n");
    exit(-1);
  }

  int scan[2000];
  int buf;

  int i=0;
  while (fscanf(fp, "%d", &buf) != EOF) {
    if (i>=2000){
      puts("Error - buffer exceeded - file too large");
      break;
    }
    scan[i++] = buf;
    
  }
  
  // Stop comparing at last entry in file
  int count=0;
  for (int j=1; j<i; j++){
    if (scan[j] > scan[j-1]) {
      count++;
    }
  }
  printf("Count for single set: %d\n", count);
  
  count=0;
  for (int j=3; j<i; j++){
    if ((scan[j] + scan[j-1] + scan[j-2]) > (scan[j-1] + scan[j-2] + scan[j-3])) {
      count++;
    }
  }
  printf("Count for single set: %d\n", count);

  return 0;
}
