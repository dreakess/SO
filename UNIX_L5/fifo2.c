#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {

	int fd;
	char * myfifo = "/tmp/myfifo";
	mkfifo(myfifo, 0666);
	
	char arr1[128], arr2[128];

	while (1) {
	
		fd = open(myfifo, O_RDONLY);
		read(fd, arr1,128);
		printf("User1: %s\n", arr1);
		close(fd);
		
		fd = open(myfifo, O_WRONLY);
		fgets(arr2, 128, stdin);
		write(fd, arr2, strlen(arr2)+1);
		close(fd);
	}

	return 0;
}
