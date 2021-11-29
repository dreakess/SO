#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define N 32


void recur_to_up(char * in_str);
static char * tmp;

int main(){

	char * vet = calloc(N, sizeof(char));	
	printf("inserire almeno 5 parole: ");
	fgets(vet, N, stdin);

	vet = vet + N -1;

	recur_to_up(vet);
	
	printf("(dopo) %s\n",tmp);

	return 0;
}

void recur_to_up(char * in_str){
	printf("%s\n", in_str);
	if(*in_str == '\0') {printf("ciao\n"); return;}
	else {
		if(ispunct((int)*in_str) || isblank((int)*in_str) || isspace((int)*in_str) || isdigit((int)*in_str) || isupper((int)*in_str)){ 
			*tmp = *in_str;
			++tmp;			
			recur_to_up(++in_str);
		}
		else {
		
		*tmp = (char)toupper(*in_str);
  		printf("%c\n", *tmp);
		++tmp;
		printf("%s\n", in_str);
		recur_to_up(in_str+1);
		}
	}
}
