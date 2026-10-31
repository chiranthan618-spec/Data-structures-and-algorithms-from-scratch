#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 20

int Stack[MAX];
int top = -1;

void push(int x){
    Stack[++top] = x;
}

int pop(){
    return Stack[top--];
}

int evaluatePostfix(char *exp){
    char *token = strtok(exp, " ");

    while(token != NULL){
        if(isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))){
            push(atoi(token));
        }
        else{
            int val2= pop();
            int val1 = pop();
            switch(token[0]){
                case '+':push(val1+val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1*val2); break;
                case '/': push(val1/val2); break;
                case '^':{
                    int res = 1;
                    for(int j = 0;j < val2; j++){
                        res *= val1;
                    }
                    push(res);
                    break;
                }
            }
        }
        token = strtok(NULL, " ");
    }
    return pop();
}

int main(){
    char exp1[] = "12 3 + 5 *";
    char *e;

    e = exp1;


    printf("Result: %d\n", evaluatePostfix(e));

    return 0;
}