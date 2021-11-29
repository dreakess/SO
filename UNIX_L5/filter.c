#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<ctype.h>

int main(){ 

	char ch;
	
	while((ch = getchar()) != EOF) {
		putchar(toupper(ch));
	}

	exit(EXIT_SUCCESS);
	return 0;
}
