#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static void dd_signal_handler(int sig){
	printf("ricevuto segnale SIGTERM!!!\n");
}

void errExit(char * c){
	printf("%s\n", c);	
}

int main() {

	if(signal(SIGTERM, dd_signal_handler) == SIG_ERR) 
		errExit("signal (SIG_ERR) error");
		
	while(1) sleep(1);
	exit(EXIT_SUCCESS);

	return 0;
}
