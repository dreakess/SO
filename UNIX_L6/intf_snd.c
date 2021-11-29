#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

struct queue { long mtype; char mtext[256];};
int main() {

	char ch[256];
	int term;
	
	int m = msgget(1234, IPC_CREAT | 0666);
	struct msqid_ds tmp;
	struct queue q;

	
	printf("inserire stringa e poi un intero: ");
	scanf("%d ", &term); 
	for(;term>=0;) {
		fgets(q.mtext, 256,stdin);
	
		q.mtype = m;
		if(msgsnd(m, &q, sizeof(q), IPC_NOWAIT) == -1) {printf("errore..\n");}
		msgctl(m, IPC_STAT, &tmp);	
		
		printf("mex: %s \ntempo dell' ultimo mex : %s\n", q.mtext, ctime(&(tmp.msg_stime)));
		printf("inserire stringa e poi un intero: ");
		scanf("%d ", &term);
	}
	

	return 0;
}
