#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
	
	int m = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
	struct msqid_ds tmp;

	if(m != -1){
		msgctl(m, IPC_STAT, &tmp);
		printf("dimensione coda: %ld \nnum. mex in coda: %ld\ntempo dell' ultimo mex : %s\n", tmp.msg_qbytes, tmp.msg_qnum,
 		ctime(&tmp.msg_stime));
		
	}
	else {printf("ipc non creata.. \n");}

	struct queue { long mtype; char mtext[256];};
	struct queue q;
	q.mtype = m;
	if(msgsnd(m, &q, sizeof(q), IPC_NOWAIT) == -1) {printf("errore..\n");}
	msgctl(m, IPC_STAT, &tmp);	
	printf("tempo dell' ultimo mex : %s\n", ctime(&(tmp.msg_stime)));

	
	msgctl(m, IPC_RMID, NULL);	

	return 0;
}
