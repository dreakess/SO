#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	
	for(int i = 0; i < 3; i++){
		switch(fork()){
			case 0: printf("(pid_figlio) %d \n", getpid()); 
			default: printf("(pid_padre) %d *\n", getpid()); 
		}
	}
	
	return 0;
}
