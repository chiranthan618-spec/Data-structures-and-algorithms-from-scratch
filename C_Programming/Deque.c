//In normal queue, we can push using rear and hence rear moves forward. Similarly we can pop from front and front moves forward.
//But in deque, we can push using front and front moves backward. Similarly, we pop using rear and rear moves backward



#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int deque[MAX];
int front = -1;
int rear = -1;

void insertFront(int x){
    if((front == 0 && rear == MAX-1) || (front == rear + 1)){
        printf("Deque overflow\n");
        return;
    }
    if(front == -1){
        front = rear = 0;
    }
    else if(front == 0){
        front = MAX - 1; //So, when front reaches 0, in order push we attach it to the MAX -1 in a circular way.
    } else {
        front -= 1;
    }
    deque[front] =x;
}

void deleteRear(){
    if(front == -1){
        printf("deque underflow\n");
        return;
    }
    else if(front == rear){
        front = rear = -1;
    }
    else if(rear == 0){
        rear = MAX-1;
    } else{
        rear -= 1;
    }
}