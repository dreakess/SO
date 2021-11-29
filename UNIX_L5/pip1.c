int main(int argc, char *argv[]) {

	int pfd[2];
	char bu[32];
	int numRead;
	
	pipe(pfd);
	
	switch(fork()) {

		case 0: {
			close(pfd[1]);
			
			for(;;) {
				
				numRead = read(pfd[0],buf, 32);
				if(numRead == -1);
				if(numRead == 0);

				if(write(STDOUT_FILENO, buf, numRead) != numRead);			
			}
			write(STDOUT_FILENO, "\n", 1);
			close(pfd[0]);
			exit(EXIT_SUCCESS);			
		}
		default: {

			close(pfd[1]);

			write(pfd[1], argv[1], strlen(argv[1]));
			wait(NULL);

			exit(EXIT_SUCCESS); 
		}
	} 

	return 0;
}
