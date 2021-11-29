#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#define MAX_CMD_LEN 10


int main(){
	
	char str[MAX_CMD_LEN];
	int status;
	
	for(;;){
	
		printf("Command: ");
		fflush(stdout);
		
		if(fgets(str, MAX_CMD_LEN, stdin)){
		 break;}
		 
		status = system(str);
		printf("system() returned: status=0x%04x\n"
		, (unsigned int) status);
		
		if(status == -1){}
		 //errExit("system"); // funzione inesistente 
		else {
			if(WIFEXITED(status) && WEXITSTATUS(status) == 127)
				printf("(Probably) could not invoke shell\n");
			//else
				//print_wait_status(NULL, status );
			} 
	}
	exit(EXIT_SUCCESS);
}

