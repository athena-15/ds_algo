#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void foo(char* c){
 
	c = (char*)malloc(10);
	strcpy(c, "new_string");
	printf("\n%s", c);
}
 
 
int main(){
 
	char* c = (char*)malloc(10);
	strcpy(c, "old_string");
	printf("\n%s", c);
	foo(c);
	printf("\n%s", c);
	return 0;
}
