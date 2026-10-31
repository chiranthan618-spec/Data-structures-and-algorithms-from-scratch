#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int multi[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int x){
    if(top1+1 == top2){
        printf("Stack  overflow\n");
        return;
    }
    multi[++top1] = x;
}

void push2(int x){
    if(top1 + 1 == top2){
        printf("Stack overflow\n");
        return;
    }
    multi[--top2] = x;
}

int pop1(){
    if(top1 == -1){
        printf("Stack underflow\n");
        return -1;
    }
    return multi[top1--];
}

int pop2(){
    if(top2 == MAX){
        printf("Stack underflow\n");
        return -1;
    }
    return multi[top2++];
}

int main(){
    push1(10);
    push2(20);

    printf("Popped: %d", pop1());
    printf("popped 2: %d", pop2());
}