//Types of Priority Queues
//1. Ascending Priority Queue – Smallest key has the highest priority
//(deletion removes the smallest element first).
//2. Descending Priority Queue – Largest key has the highest priority (deletion removes the largest element first).
//3. Double-Ended Priority Queue – Allows deletion of both highest and lowest priority elements.
//Operations on Priority Queue
// Insert(item, priority)
//Adds an element along with its priority.
//Inserted at the correct position according to priority.
// Delete()
//Removes the element with the highest priority.
// Peek()
//Returns the highest-priority element without removing it.


#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct item {
    int data;
    int priority;
};

struct item queue[MAX];
int front = -1;
int rear = -1;

void push(struct item newItem){
    if(rear == MAX - 1){
        printf("Queue overflow\n");
        return;
    }
    if(front == -1){
        front = rear = 0;
    }
    else{
        rear++;
    }
    queue[rear] = newItem;
}

struct item dequeue(){
    if(front == -1){
        printf("Stack underflow;");
        struct item empty = {-1, -1};
        return empty;
    }   
    int highest = front;
    for(int i = front + 1; i <= rear; i++){
        if(queue[i].priority > queue[highest].priority)
            highest = i; 
    }
    struct item deleted = queue[highest];
 
    if(front == rear){
        front = rear = -1;
    } else{
        rear--;
    } 
    return deleted;
}

int main(){   
    struct item temp;
    int option; 
    while(1){
        printf("Select option: 1)push 2) pop 3)exit");
        scanf("%d", &option);
        switch(option){
            
            case 1:
            printf("Enter the data and priority: ");
            scanf("%d %d", &temp.data, &temp.priority);
            push(temp);
            break;

            case 2:
            {
                struct item popped = dequeue();
                if(popped.data != -1){
                    printf("Popped item: %d", popped.data);
                }
            }

            case 3:
            return 0;

            default:
            printf("Invalid");
        }
    }
    return 0;
}