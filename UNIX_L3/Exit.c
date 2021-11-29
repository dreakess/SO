#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	
	printf("Hello World \n");	
	write(STDOUT_FILENO, "Ciao\n", 5);
	//fflush(stdout);

	if(fork() == -1) 
		errExit("fork");

	exit(EXIT_SUCCESS);
}
