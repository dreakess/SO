#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void handler(int);

struct sigaction Sa;
int flag = 1;

int main() {
		int c;
		sigset_t my_mask;
		Sa.sa_handler=&handler;
		sigemptyset(&my_mask);
		Sa.sa_mask = my_mask;
		sigaction(SIGSTOP, &Sa, NULL);
		
		switch(c= fork()){
			
			case 0: {
				//signal(SIGINT, &handler);
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
	if(flag){
	printf("segnale gestito dal nuovo handler: SIGINT\n");
	//signal(SIGINT, SIG_IGN);
	flag = 0;
	sigaction(SIGSTOP,&Sa, NULL);
	}
	else {	flag = 1; sigaction(SIGCONT,&Sa, NULL);}
}
