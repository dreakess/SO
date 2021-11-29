#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void recur_to_up(char * in_str);
static char * tmp;
int main(){
		
	char *prova = "Paolo Rossi";
	printf("(prima) %s\n", prova);	
	
	tmp = calloc(strlen(prova), sizeof(char));	
	char * finale = tmp;
	recur_to_up(prova);
	
	printf("(dopo) %s\n",finale);

	return 0;
}

void recur_to_up(char * in_str){

	if(*in_str == '\0') {return;}
	else {
		if(ispunct((int)*in_str) || isblank((int)*in_str) || isspace((int)*in_str) || isdigit((int)*in_str) || isupper((int)*in_str)){ 
			*tmp = *in_str;
			++tmp;			
			recur_to_up(++in_str);
		}
		else {
		
		*tmp = (char)toupper(*in_str);
  		//printf("%c\n", *tmp);
		++tmp;
		//printf("%s\n", in_str);
		recur_to_up(in_str+1);
		}
	}
}
