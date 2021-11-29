#include <stdlib.h>
#include <stdio.h>

int main(){

	printf("Hello world\n");
	write(STDOUT_FILENO, "Ciao \n", 5); //system call per printare
	
	// il motivo del perche' quando ridiregiamo verso un altro file, stampa: Ciao Hello World Hello World
	
	// perche' quando andiamo a redirigere verso file la printf non svuota il buffer ma mantiene la bufferizzazione,
	// quindi alla chiamta della fork avremo l'invocazione della fork con le due print e Hello World
	
	if(fork() == -1){
		errExit("fork");
	}
	
	exit(EXIT_SUCCESS);
}
