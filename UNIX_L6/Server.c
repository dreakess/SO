#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>

struct queue { long mtype; char mtext[256];};
int main() {

	char ch[256];
	int term;
	
	int m = msgget((key_t)1234, IPC_CREAT | 0666);
	
	struct queue q;
	
	for(;;){
		printf("_");
		if(msgrcv(m, &q, sizeof(q),0,0) != -1){
		  if(strcmp(q.mtext, "") == 0) {msgctl(m, IPC_RMID, NULL); exit(0);}
		  else{
			if(fork() == 0) {
				struct queue qresp;
				msgrcv(m, &qresp, sizeof(qresp),0,0);
				printf("[server](figlio %d) richiesta: %s \n", getpid(), qresp.mtext);
				struct queue resp;
				resp.mtype = q.mtype;
				strncpy(resp.mtext, "si", 2);
				msgsnd(m, &resp, sizeof(resp), IPC_NOWAIT);
				exit(0);
			}
			else {msgsnd(m, &q, sizeof(q), IPC_NOWAIT);}
		      }
		}
	}

	return 0;
}
