#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main()
{	
	size_t n = fork();
	pid_t pid = 0;

	if(!n) { printf("(figlio %d) sono operativo..(tra poco mi sospendo)\n", getpid()); 
		pid = getpid();		
		for(int i=0; i<3;i++){printf("* ");sleep(2);printf("* * \n");}
		exit(0);
	}
	else{
		if(kill(pid, SIGKILL)){printf("(padre %d) processo figlio %d ucciso!\n", getpid(), pid);}
		else{printf("errore..\n");}
		exit(0);
	}	
	
	return 0; 
}
