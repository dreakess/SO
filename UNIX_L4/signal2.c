#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static void dd_signal_handler(int sig){
	static int count = 0;
	
	if(sig == SIGINT){
		count++;
		printf("intercettato SIGINT (%d)\n", count);
		return; 
	}

	printf("intercettato SIGQUIT - termino!!!\n"); // SIGTQUIT = CTRL + \
	exit(EXIT_SUCCESS);
}

void errExit(char * c){
	printf("%s\n", c);	
}

int main() {
	

	if(signal(SIGINT, dd_signal_handler) == SIG_ERR) 
		errExit("signal (SIGINT) error");
	if(signal(SIGQUIT, dd_signal_handler) == SIG_ERR) 
		errExit("signal (SIGQUIT) error");
		
	
	for(;;){
		pause();
	}

	return 0;
}
