#include<stdio.h>

int main() {

	FILE * fp;
	char path[32];
	fp = popen("ls", "r");
	
	while(fgets(path, 32, fp) != NULL)
		printf("%s", path);
		
	pclose(fp);	 
	
	return 0;
} 
