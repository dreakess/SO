#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>


int main() {
		int pid = 0;
		printf("Inserire pid:(intero) ");
		scanf("%d", &pid);
			
		if(kill(pid, 0) == -1) {printf("%s", strerror(errno));}
	
		return 0;
}

