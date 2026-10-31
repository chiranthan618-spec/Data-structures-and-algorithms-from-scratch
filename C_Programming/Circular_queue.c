#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = MAX- 1;

//1. Uses modulus (%) operator to wrap around when the end of the array is reached.
//2. Both front and rear pointers move circularly.
//3. Eliminates memory wastage problem.
//4. Follows FIFO (First In – First Out) principle.

void enqueue(int item){
    if((front == 0 && rear == MAX - 1) || (front == (rear+1)%MAX)){
        printf("Queue overflow\n");
        return;
    } 
    if(front == -1){
        front = rear = 0;
    }
    else{
        rear = (rear+1) % MAX;
    }

    queue[rear] = item;
}

int dequeue(){
    int item;
    if(front == -1){
        printf("Queue underflow\n");
        return -1;
    }
    item = queue[front];
    if(front == rear){
        front = rear = -1;
    } else {
        front = (front+1) % MAX;
    }
    return item;
}
