#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 20


int top=-1;
char stack[max];  //string is a character array..
char pop();
void push (char);

int main(){
    char str[20];
    unsigned int i;
    printf("enter the string: ");
    gets(str);

    for (int i=0; i<strlen(str); i++){
        str[i]=pop();

        printf ("reversed string is: ");
        puts(str);
    }

    return 0;
}


void push (char item){
    if (top==(max-1)){
        printf ("stack overflow: ");
       
        return;
    }
    stack[++top]=item;
}

char pop(){
    if (top==-1){
        printf ("stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

  
