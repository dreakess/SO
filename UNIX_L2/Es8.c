#include <stdio.h>

int main(){
	
	char vet[6];
	int i = 1, k = 0;
	while(i < 10) {
	
		for(k = 1; k <= 10; ++k) {printf("%c ", (char)(i*k)); }
		printf("\n");
		for(k=1; k <= 10; k++) {printf("- ");}	
		printf("\n");
		++i; 
	}	
		
	return 0;
}
