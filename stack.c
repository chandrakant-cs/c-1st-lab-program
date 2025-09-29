#include<stdio.h>
#define size 10

void push(int);
void pop();
void peek();
void display();
int stack[size];
int top=-1;

int main(){
    int choice;
    int value;
    while(1){
        printf("\nEnter a choice:\n1.push\n2.pop\n3.peek\n4.exit\n ");
        scanf("%d",&choice);

        switch (choice){
            case 1:printf("Enter value");
                    scanf("%d",&value);
                    push(value);
                    display();
                    break;
            
            case 2:pop();
                    display();
                    break;
            
            case 3:peek();
                    display();
                    break;

            case 4:return(0);

            default : printf("enter a correct choice");
        }

    }
}

void push(int value){
    if (top==size-1){
        printf("stack is overflow");
    }
    else{
        top++;
        stack[top]=value;
        printf("pushed");
    }
}

void pop(){
    if (top==-1){
        printf("stack is under flow");
    }
    else{
        printf("poped:%d",+stack[top]);
        top--;
    }
}

void peek(){
    if (top==-1){
        printf("stack is empty");
    }
    else{
        printf("peek is %d:",stack[top]);
    }
}

void display(){
    int i;
    if (top==-1){
        printf("stack is empty");
    }
    else{
        for(i=top;i>=0;i--){
            printf("\nstack elements are;%d",stack[i]);
        }
    }
}