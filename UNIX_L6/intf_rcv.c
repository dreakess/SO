#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

struct queue { long mtype; char mtext[256];};
int main() {

	char ch;
	int term;
	
	int m = msgget((key_t)1234,0);
	struct msqid_ds tmp;
	struct queue q;

	printf("quale messaggio prelevare: ");
	scanf("%d", &term);
	
	for(;term >= 0;) {
		q.mtype = getpid();
		if(msgrcv(m, &q, sizeof(q),term,0) == -1) {printf("errore..\n");}
		
		printf("%s", q.mtext);

	printf("\nquale messaggio prelevare: ");
	scanf("%d", &term);
	printf("\n");
}
	return 0;
}
