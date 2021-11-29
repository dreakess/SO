#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main() {
	
	FILE * pipe;
	int ch;
	
	if((pipe = popen("./filter", "r")) == NULL) {
		fputs("Errore nell'apertura del pipe!\n", stderr);
		exit(EXIT_FAILURE);
	}

	printf("sto leggendo dal pipe. PID: %d\n", getpid());

	while((ch = getc(pipe)) != EOF) {
		putchar(ch);
	}

	
	pclose(pipe);
	exit(0);
		
	return 0;
}
