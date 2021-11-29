#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 128
char** leggi_lista(FILE* file_in, int* nof_elements);
void stampa_lista(char** mio_ar, int n_elems);

int main() {
	
	FILE * fp = fopen("lista_nomi.txt", "r");
	char * value = calloc(N,sizeof(char));
	char* tmp=value;
	int *i = malloc(sizeof(int));
	*i = 0;
	while(fgets(value, N, fp) != NULL){
		*i +=1;
	}
	printf("%d\n", *i);
	stampa_lista(leggi_lista(fp, i), *i);	
	//leggi_lista(fp, i);
	fclose(fp);
	return 0;
}

// PRE: il numero di righe del file corrisponde 
//      esattamente al numero degli elementi
// 

char** leggi_lista(FILE* file_in, int* nof_elements) {
		
		char * value= calloc(N,sizeof(char));
		char ** values = calloc(*nof_elements, sizeof(char ));
		char ** tmp = values;
		rewind(file_in);
		
		while(fgets(value, N, file_in) != NULL){
			*values = strdup(value);
			printf("%s", *values);
			values++;
		}
		return tmp;
}

void stampa_lista(char ** mio_ar, int n_elems){
	int i;
	for(char** pun =mio_ar,  i= 0; i < n_elems; i++, pun++){
		printf("%s", *pun);
	}
}
