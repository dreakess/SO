#include<stdio.h>
#include<stdlib.h>
#define N 56 

char *parse_name(char * stringa_completa[]);

int main(int argc, char *argv[])
{
	char *stringa_completa[N];
	
	printf("inserire un nome e un cognome: ");
	fgets(stringa_completa, N, stdin); 
	printf("%s \n", stringa_completa);
	printf("%s \n", parse_name(stringa_completa));
	return 0;
}

char * parse_name(char * a[]){

	char * tmp = a;
	printf("%s\n", tmp);	
	char * ret = calloc(N,sizeof(char));
	int f = 1;
	while(*tmp != EOF &&f){
		if(*tmp == ' ' || *tmp == '\n' || *tmp == '\t' || 101<=(int)*tmp && (int)*tmp <= 132){f=0;}	
		*ret = *tmp;
		++ret;
		++tmp;
	}
	return ret;
}


