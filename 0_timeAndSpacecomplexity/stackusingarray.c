#include <stdio.h>
#include <stdlib.h>   // for dynamic memory allocation
#define max 10


int stack_arr[max];   // array with name stack_arr and size max...
int top = -1;
void push (int item);  // function prototype
int pop();
int peek();
int isempty();
int isfull();

void show(){
    int i;
    if (isempty())  printf("stack is underflow\n");   
    else{
        printf("elements of stack is \n");
        for (i = top ; i >= 0; i--)
        {
            printf("%d \n", stack_arr[top]);
        }
    }
}


int main()
{
    int choice, item, s = 0;
    while (s <= 3)
    {
        printf ("1. push \n");
        printf ("2. pop \n");
        printf ("3. display the top element \n");
        printf ("4. display all stack element \n");
        printf ("5. quit \n");
        printf ("enter your choice: ");
        scanf ("%d ", &choice); 
        
        switch (choice)
        {
            case 1:{
                printf("enter the item to be pushed: ");
                scanf ("%d", &item);
                push(item);
                break;  // break nahi lagaya to aage ke bhi case chalne lagenge..
            }

            case 2:{
                item =pop();
                printf("popped item is: %d\n", item);
                break;
            }

            case 3:{
                printf ("item at the top is: %d\n", peek());
                break;
            }

            case 4:{
                show();
                break;
            }

            case 5:{
                exit(1);
            }

            default:{
                printf("wrong choice\n");
            }
        }        
        s++;
    }
    return 0;
}

int pop()
{
    int item ;
    if (isempty())
    {
        printf("stack underflow \n");
        exit(1);
    }
    else
    {
        item = stack_arr[top];
        top = top -1;
        return item;
    }
}

void push(int item)
{
    if (isfull())
    {
        printf("stack overflow \n");
        return ;
    }
    else
    {
        top = top +1;
        stack_arr[top] = item;
    }
}

int isempty()
    {
        if (top == -1)
        {
            return 1;  // this means stack is empty
        }
        else 
        {
            return 0;
        }
    }

int isfull()
{
    if (top == max -1)  // this means stack is full
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int peek()
{
    if (isempty())
    {
        printf("stack is underflow\n");
        exit(1);
    }
   return stack_arr[top]; 
}
