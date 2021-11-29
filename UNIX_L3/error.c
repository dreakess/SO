#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define VEC_SIZE 5


int main(int argc, char * argv[]){


	char *argVec[VEC_SIZE] = {"buongiorno", "ciao", "cordiali saluti", "all the best", NULL};
	char *envVec[VEC_SIZE] = {"silvia", "paolo", "mario", "carla", NULL};	

	switch(fork()) {
		
		case -1:
		fprintf(stderr, "fork fallita\n");
		exit(0);
		
		case 0: 
		printf("PID(figlio): %d\n",getpid());
		execve(argv[1], argVec, envVec);

		default:
		printf("PID(padre) %d\n", getpid());
		printf("---- padre dorme per tre sec ----\n");
		for(int i = 0; i < 3; i++) {
			sleep(1);
			printf("*\n");
		}
	
		printf("--- terminazione del processo padre ---\n");	
		exit(EXIT_SUCCESS);
		
	}
	
	return 0;
}
