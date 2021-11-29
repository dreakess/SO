#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char * argv[]) {

	int fd[2];
	int p;
	
	p = pipe(fd);
		
	for(int i=0; i<3;i++) {
		switch(fork()) {
			
			case 0: {
				printf("(figlio %d) mi metto a dormire per %d sec.. \n", getpid(), atoi(argv[i]));
				sleep(atoi(argv[i]));
				close(fd[0]);
				//exit(0);			
			}
			default: {
				break;
			}
		}
	}

				close(fd[1]);
				char ch;
				if(read(fd[0], &ch, 1) != 0) {printf("(padre) non ho ricevuto l'EOF\n");}
				printf("(padre): dopo i miei figli , sto per terminare anche io..\n");
				exit(EXIT_SUCCESS);	
	
	
	return 0;
}
