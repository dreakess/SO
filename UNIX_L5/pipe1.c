#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char * argv[]){

	int fd[2];
	char buf[64];
	ssize_t numRead;
	
	pipe(fd);
	
	switch(fork()) {
		
		case 0: {
			if(argc == 3) {
				pipe(fd);
				if(fork() == 0) {
					close(fd[1]);
					write(STDOUT_FILENO, "(figlio 2)", 10);
					for(;;) {
						numRead = read(fd[0], buf, 64);
						write(STDOUT_FILENO, buf, numRead);
						}
					write(STDOUT_FILENO, "\n", 1);
					exit(0);
				}else {wait(NULL);}
				}
			close(fd[1]);
			write(STDOUT_FILENO, "(figlio 1)", 10);
			for(;;) {
				numRead = read(fd[0], buf, 64);
				write(STDOUT_FILENO, buf, numRead);
			}
			write(STDOUT_FILENO, "\n", 1);
			close(fd[0]);
			exit(0);
		}
		default: {
			close(fd[0]);
			printf("(padre) attendo la terminazione dei figli..\n");
			write(fd[1], argv[1], strlen(argv[1]));
			close(fd[1]);
			wait(NULL);
			exit(0);
		}	
	}	
	
	return 0;
}
