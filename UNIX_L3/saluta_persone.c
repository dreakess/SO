#include <stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	
	for(int i=0; i < argc; i++) {
		
		printf("%s\n", argv[i]);
	}	
	fflush(stdout);
	exit(0); 

	return 0;
}
