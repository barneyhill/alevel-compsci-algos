#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int queue[10];
int start = 0, end = 0;
int max = 10;
void removeItem(){
  int empty = 1, i;
  for (i = 0; i < max; i++){
    if (queue[i] != 0){
      empty = 0;
    }
  }
  if (empty == 1){
    printf("Array is empty!");
    return;
  }
  queue[start] = 0;
  start +=1;
  if (start > max -1){
    start = 0;
  }
}

void add(int data){
  int empty = 1, i;
  for (i = 0; i < max; i++){
    if (queue[i] == 0){
      empty = 0;
    }
  }
  if (empty == 1){
    printf("Array is full!");
    return;
  }
  queue[end] = data;
  end += 1;
  if (end > max -1){
    end = 0;
  }
}
int main(){
  int n = 10;
  int i;
  while(1==1){
    for (i = 0; i < n; i++){
  	    printf("%d", queue[i]);
  	    if (i!=n-1){
  	    	printf(",");
  	    }
        else{
          printf("\n");
        }
  	}
    char str[50];
    printf("(a)dd or (r)emove?: ");
    gets(str);
    if (strcmp(str, "a") == 0){
      printf("Enter a number:");
      int data;
      scanf("%d", &data);
      add(data);
    }
    else if (strcmp(str, "r") == 0){
      removeItem();
    }
  }
  return(0);
}
