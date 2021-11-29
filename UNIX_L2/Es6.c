#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 256

int main(){
	
	FILE* fd = fopen("complexity.txt", "r");
	int cont = 0;
	if(fd != NULL) {
			char * vet = calloc(N, sizeof(char));	
			while(fgets(vet,N, fd) != NULL) {
				if(strstr(vet, "computational") != NULL) {printf("%s\n", vet); ++cont;}
			}
	}
	
	printf("cont : %d\n", cont);	
	
	return 0;
}
