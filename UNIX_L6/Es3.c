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
	
	int m = msgget(1234, IPC_CREAT | 0666);
	struct msqid_ds tmp;
	struct queue q;
	struct queue qresp;
	switch(fork()) {
		
		case 0: {
			strncpy(q.mtext, "saluti da ", 11);
			printf("(figlio) stampo %s e %d \n",q.mtext, getpid());
			q.mtype = getpid();
			if(msgsnd(m, &q, sizeof(q), IPC_NOWAIT) == -1) {printf("errore..\n");}
			exit(0);
		}
		
		default: {
			printf("(padre) mi metto in wait.. [stampero'] \n");
			wait(NULL);
			if(msgrcv(m, &qresp, sizeof(q),0,0) == -1) {printf("errore..\n");}
			printf("%s %d \n",qresp.mtext, qresp.mtype);
			msgctl(m, IPC_RMID, NULL);
			exit(0);	
		}
	}
	
	return 0;
}
