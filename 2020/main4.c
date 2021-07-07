#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Passport {
  int byr; // birthyear
  int iyr; // issueryear
  int eyr; // expirationyear
  char hgt[10]; // height
  char hcl[10]; // haircolor
  char ecl[10]; // eyecolor
  int pid; // passpordid
  int cid; // countryid **optional**
};

int main() {
  FILE *fp;
  if ((fp = fopen("input4", "r")) == NULL) {
    puts("Error reading file");
    exit(-1);
  }

  char buf[100];
  struct Passport tmpPassport;

  while (fgets(buf, sizeof buf, fp) != NULL) {
    if (*buf != '\n') {
      char *ptr;
      char delim[] = " :\n";

      ptr = strtok(buf, delim);
      while (ptr != NULL) {
        if (strcmp(ptr, "byr") == 0) {
          ptr = strtok(NULL, delim);
          tmpPassport.byr = atoi(ptr);
          printf("Birth Year found!!!, %d\n", tmpPassport.byr);
        } 
        else if (strcmp(ptr, "iyr") == 0) {
          ptr = strtok(NULL, delim);
          tmpPassport.iyr = atoi(ptr);
          printf("Issue Year found!!!, %d\n", tmpPassport.iyr);
        } 
        else if (strcmp(ptr, "eyr") == 0) {
          ptr = strtok(NULL, delim);
          tmpPassport.eyr = atoi(ptr);
          printf("Expiration Year found!!!, %d\n", tmpPassport.eyr);
        } 
        else if (strcmp(ptr, "hgt") == 0) {
          ptr = strtok(NULL, delim);
          strcpy(tmpPassport.hgt, ptr);
          printf("Height found!!!, %s\n", tmpPassport.hgt);
        } 
        else if (strcmp(ptr, "hcl") == 0) {
          ptr = strtok(NULL, delim);
          strcpy(tmpPassport.hcl, ptr);
          printf("Hair Color found!!!, %s\n", tmpPassport.hcl);
        } 
        else if (strcmp(ptr, "ecl") == 0) {
          ptr = strtok(NULL, delim);
          strcpy(tmpPassport.ecl, ptr);
          printf("Eye Color found!!!, %s\n", tmpPassport.ecl);
        } 
        else if (strcmp(ptr, "pid") == 0) {
          ptr = strtok(NULL, delim);
          tmpPassport.pid = atoi(ptr);
          printf("Passport ID found!!!, %d\n", tmpPassport.pid);
        } 
        else if (strcmp(ptr, "cid") == 0) {
          ptr = strtok(NULL, delim);
          tmpPassport.cid = atoi(ptr);
          printf("Country ID found!!!, %d\n", tmpPassport.cid);
        } 
        else {
          printf("key is: %s\n", ptr);
          ptr = strtok(NULL, delim);
          printf("value is: %s\n", ptr);
        };
        ptr = strtok(NULL, delim);
      };
    };
  };

  fclose(fp);
  return 0;
}
