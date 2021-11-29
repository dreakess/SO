#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

#define SIZE 1024

int cont(char * a) {
	int i;
	char * pun;
	for(i=0, pun = a; *pun != '\0'; pun++, i++);
	return i;
}

int main()
{
	pid_t procPid;
	size_t valueOpen = open("esempio.txt", O_WRONLY | O_APPEND);
    	switch (procPid = fork()) {
    	case -1:
    
   	case 0:  // - - - - codice del figlio
   		
   		if(valueOpen) {
   			char *string= calloc(SIZE, sizeof(char));
   			fprintf(stdout, "(figlio) scrivi qualcosa..\n");
   			fgets(string, SIZE, stdin);
   			printf("(figlio) sto salvando: %s\n", string);
   			write(valueOpen, string, cont(string));
   		}
   		close(valueOpen);	
   		exit(0);
        	break;
    	default: // - - - - codice del genitore
    		size_t valueOpen = open("esempio.txt", O_RDONLY);
        	size_t ret = wait(NULL);
        	char *c= calloc(SIZE, sizeof(char));
        	if(valueOpen){
        		size_t t = read(valueOpen, c, SIZE);
        		if(t != -1) {fprintf(stdout, "(padre) "); fprintf(stdout, c);}
        	}
        	close(valueOpen);
        	exit(0);
        	break;
    }
	
	return 0;
}
