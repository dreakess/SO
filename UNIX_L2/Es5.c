#include<stdio.h>
#include <ctype.h>

int main()
{	
	//char * a = "Kn\"eqtuq\"hqtpkueg\"wp(kpvtqfw|kqpg\"cn\"nkpiwcciik";	

	while(*a != '\0') {printf("%c", (char)(*(a)-2)); ++a;}
	printf("\n");
	
	return 0;
}
