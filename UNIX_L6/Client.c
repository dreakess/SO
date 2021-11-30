#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>

struct queue { long mtype; char mtext[256];};
int main(int argc, char * argv[]) {

	if(argc != 1){
	char ch[256];
	int term;
	
	int m = msgget((key_t)1234, 0);
	
	//struct msqid_ds tmp;
	struct queue q;
	
	for(int i = 0; i < atoi(argv[1]); i++) {
	
		switch(fork()) {
		
			case 0:{
				struct queue resp;
				printf("[client](figlio %d) invio richiesta al server..\n", getpid());
				q.mtype = getpid();
				printf("che richiesta invio: \n");
				scanf("%s", q.mtext);
				msgsnd(m, &q, sizeof(q), IPC_NOWAIT);
				if(msgrcv(m, &resp, sizeof(resp),getpid(),0) != -1){
					printf("[client](figlio %d) ricevuto dal server: %s \n", getpid(),resp.mtext);
				}
				else {exit(0);}
			}

			default: {
				wait(NULL);
			}
		}
	}
 }
 	else {printf("argc carenti..\n");}
	return 0;
}
