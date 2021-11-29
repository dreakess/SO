#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
		
	for(;;){
		printf("*\n");
		sleep(3);
		printf("|\n");
		sleep(2);
	}

	return 0;
}
