#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Rule {
  int num1;
  int num2;
  char letter;
  char *password;
};

struct Rule load_rule(char *str) {
  struct Rule tmprule;

  tmprule.num1 = atoi(strtok(str, "- :"));
  tmprule.num2 = atoi(strtok(NULL, "- :"));
  tmprule.letter = *strtok(NULL, "- :");
  tmprule.password = strtok(NULL, "- :");

  return tmprule;
}

int part1(struct Rule tmprule) {
  int count = 0;
  for (int i = 0; i < (int)strlen(tmprule.password); i++) {
    if (tmprule.letter == tmprule.password[i]) {
      count++;
    }
  }
  if ((count >= tmprule.num1) && (count <= tmprule.num2)) {
    return 1;
  } else {
    return 0;
  }
}

int part2(struct Rule tmprule) {
  if ((tmprule.password[tmprule.num1 - 1] == tmprule.letter) ^
      (tmprule.password[tmprule.num2 - 1] == tmprule.letter)) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  FILE *fp;
  if ((fp = fopen("input2", "r")) == NULL) {
    puts("Error reading file");
    exit(-1);
  }

  char buf[200];
  int part1_count = 0, part2_count = 0;

  while (fgets(buf, sizeof buf, fp) != NULL) {
    struct Rule tmprule = load_rule(buf);
    part1_count += part1(tmprule);
    part2_count += part2(tmprule);
  }

  printf("Part1 Pass Count: %d\n", part1_count);
  printf("Part2 Pass Count: %d\n", part2_count);

  fclose(fp);
  return 0;
}
