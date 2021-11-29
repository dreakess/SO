#include <stdio.h>
#include <signal.h>
#include <unistd.h>



static void dd_signal_handler(int sig){
	printf("-----\n");
}

void errExit(char * c){
	printf("%s\n", c);	
}

int main() {
	
	int j;

	if(signal(SIGINT, dd_signal_handler) == SIG_ERR) 
		errExit("signal (SIG_ERR) error");
		
	for(j=0; ;j++){
		printf("%d\n", j);
		sleep(1);
	}

	return 0;
}
