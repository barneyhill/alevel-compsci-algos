#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int stack[10];
int top = 0;
int max = 10;

void push(data){
	if (top >= max){
		printf("Overflow!");
		return;
	}
	stack[top] = data;
	top++;
	return;
}

void pop(){
	top--;
	if (top < 0){
		printf("Underflow!");
		return;
	}
	stack[top] = 0;
	return;
}

int main(){
  int i;
  int n = 10;
  while(1==1){
    for (i = 0; i < n; i++){
  	    printf("%d", stack[i]);
  	    if (i!=n-1){
  	    	printf(",");
  	    }
        else{
          printf("\n");
        }
  	}
  	
    char str[50];
    printf("(p)ush or (P)op?: ");
    gets(str);
    if (strcmp(str, "p") == 0){
    	printf("Enter a number:");
    	int data;
    	scanf("%d", &data);
    	push(data);
    }
    else if (strcmp(str, "P") == 0){
      pop();
    }
  }
  return(0);
}
