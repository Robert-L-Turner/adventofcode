#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[]) {
	
	if ( argc != 2){
		printf("Usage : %s [inputfile]\n", argv[0]);
	}
	
	FILE *fp;
	if ((fp = fopen(argv[1], "r")) == NULL){
		puts("Error reading file");
		exit(-1);
	}
	
	char buf[10], buf2[10], buf3[10];
	fpos_t pos, pos2;
	int sum2 = 0, sum3 = 0;
	while (fgets(buf, sizeof buf, fp) != NULL) {
		if ( sum2 && sum3 ) {
			exit(0);
		}
		fgetpos(fp, &pos);
		fseek(fp, 0, SEEK_SET);
		while (fgets(buf2, sizeof buf2, fp) != NULL) {
			if (!sum2 && (atoi(buf) + atoi(buf2)) == 2020) {
				printf("%d * %d = %d\n", atoi(buf), atoi(buf2), (atoi(buf)*atoi(buf2)));
				sum2 = 1;
			}
			if (!sum3 && (atoi(buf) + atoi(buf2)) <= 2020){
				fgetpos(fp, &pos2);
				fseek(fp, 0, SEEK_SET);
				while (fgets(buf3, sizeof buf3, fp) != NULL) {
					if ((atoi(buf) + atoi(buf2) + atoi(buf3)) == 2020) {
						printf("%d * %d * %d = %d\n",\
							atoi(buf), atoi(buf2), atoi(buf3), (atoi(buf)*atoi(buf2)*atoi(buf3)));
						sum3 = 1;
						break;
					}
				}
				fsetpos(fp, &pos2);	
			}
		}
		fsetpos(fp, &pos);
	}	
	
	fclose(fp);
	if ( sum2 & !sum3){
		puts("No match found for 3 integers whose sum is 2020");
		exit(0);
	}
	if ( !sum2 & sum3) {
		puts("No match found for 2 integers whose sum is 2020");
		exit(0);
	}
	puts("No matches found for 2 or 3 integers whose sum is 2020");
	return 0;
}
