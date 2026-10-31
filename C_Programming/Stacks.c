#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int x){
    if(top == MAX_SIZE - 1){
        printf("Stack overflow");
        return;
    }

    else{
        top++;
        stack[top] = x;
    }
}

int pop(){
    if(top == -1){
        printf("Array is empty");
        return 0;
    }
    else{
        int value = stack[top];
        top--;
        return value;
    }
}

void display_stack(){
    if(top == -1){
        printf("Stack empty");
        return;
    }
    for(int i = 0; i <= top; i++){
        printf("%d\t", stack[i]);
    }
}

int main(){
    int n;
    while(1){
        printf("Enter the operation: {1: push | 2: pop | 3: display stack}");
        scanf("%d", &n);
        if(n == 1){
            int i;
            printf("Enter the value to be pushed: ");
            scanf("%d", &i);
            push(i);
        }
        else if(n == 2){
            pop();
        }
        else if(n == 3){
            display_stack();
        }
        else{
            printf("enter valid option");
        }
    }
    return 0;
}