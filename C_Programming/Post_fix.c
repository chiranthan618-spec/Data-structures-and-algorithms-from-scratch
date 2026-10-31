#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>̥

#define MAX_SIZE 20

char stack[20];
int top = -1;

int isEmpty(void){
    return top == -1;
}

int isFUll(void){
    return top == MAX_SIZE - 1;
}

void push(char x){
    if(isFUll()){
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = x;
}

char pop(void){
    if(isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }

    return stack[top--];
}

char peek(void){
    return stack[top];
}

int precedence(char c){
    switch(c){
        case '^':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '-':
        case '+':
            return 1;
        default:
            return 0;
    }
}

int isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

void convertInfix(char *exp){
    char result[100];
    int k = 0;
    for(int i = 0; i < (int)strlen(exp); i++){
        char c = exp[i];
        if(isalnum((unsigned char)c)){
            result[k++] = c;
        }
        else if(c == '('){
            push(c);
        }

        else if(c == ')'){
            while(!isEmpty() && peek() != '('){
                result[k++] = pop();
            }
            if(isEmpty()){
                printf("Stack underflow\n");
                return;
            }
            pop();
        }
        else if(isOperator(c)){
            while(!isEmpty() && precedence(peek()) >= precedence(c)){
                result[k++] = pop();
            }
            push(c);
        }

        else{
            printf("Invalid symbol\n");
            return;
        }
    }
        while(!isEmpty()){
            if(peek() == '(' || peek() == ')'){
                printf("Invalid infix expression");
                return;
            }
            result[k++] = pop();
        }
        result[k] = '\0';
        printf("Postfix expression: %s\n", result);
    
}

int main(){
    char exp[20];
    char *e;

    printf("Enter the expression: ");
    scanf("%s", exp);

    e = exp;

    convertInfix(e);

    return 0;
}