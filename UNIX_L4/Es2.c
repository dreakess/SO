#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void handler(int);

int main() {
		int c;
		
		switch(c= fork()){
			
			case 0: {
				signal(SIGINT, &handler);
				for(;;) {
					printf("(figlio) sto dormendo 3 sec..\n");
					sleep(3);
				}	
				exit(0);
				break;	
			}
			
			default: {
				printf("(padre) attendo mio figlio..\n");
				wait(NULL);
				exit(0);
			}	
		}
		
	
		return 0;
}


void handler(int sig) {

	printf("segnale gestito dal nuovo handler: SIGINT\n");
	signal(SIGINT, SIG_IGN);
}
