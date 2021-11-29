#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

	int value = 0;
	int i = 1;
	pid_t t;	
	
	for(; scanf("%d", &value) != EOF && (value > 1);){
		

		printf("processo %d: \n", value);		
		while(value > 0) {
			--value;	
			t = fork();
			
			if(t == 0) {
				
				printf("mi sospendo per %d sec", i);
				sleep(i);
				printf("\n");
				exit(t); 			
			}
			else {wait(NULL); ++i;}
		}
		printf("terminazione del processo\n");
		i = 1;
	}			
	
	return 0;		
}
