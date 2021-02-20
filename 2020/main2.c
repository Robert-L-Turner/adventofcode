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
	fclose(fp);
	return 0;
}
