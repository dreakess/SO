#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

static int segnale_ricevuto = 0;

static void mio_handler(int sig) {segnale_ricevuto = 1;} 

int main (){
	
	sigset_t orig_mask;
	sigset_t mask;
	struct sigaction act;

	printf("process pid: %d\n", getpid());
	memset(&act, 0, sizeof(act));	
	act.sa_handler = mio_handler;

	if(sigaction(SIGTERM, &act, 0));

	sigemptyset(&mask);
	sigaddset(&mask, SIGTERM);

	if(sigprocmask(SIG_BLOCK, &mask, &orig_mask));
	sleep(20);	
	if(sigprocmask(SIG_SETMASK, &orig_mask, NULL) < 0);
	sleep(1);
	if(segnale_ricevuto) puts("signal ricevuto!\n");  

	return 0;
}
