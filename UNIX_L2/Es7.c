#include <stdlib.h>
#include <stdio.h>

int main(){
	
	printf("LOGNAME: %s\n", getenv("LOGNAME"));
	printf("HOME: %s\n", getenv("HOME"));	
	printf("PATH: %s\n", getenv("PATH"));	

	return 0;
}
