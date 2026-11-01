//This code is for n number of tower of hanoi
#include <stdio.h>
#include <stdlib.h>

// stack node
struct StackNode {
    int disk;
    int source;
    int auxiliary;
    int destination;
    struct StackNode *next;
};

// custom stack
struct MyStack {
    struct StackNode *top;
    int size;
};

// Function to create a new stack
struct MyStack *newStack() {
    struct MyStack *stack = (struct MyStack *)malloc(sizeof(struct MyStack));
    if (stack != NULL) {
        stack->top = NULL;
        stack->size = 0;
        return stack;
    } else {
        printf("Stack overflow\n");
        return NULL;
    }
}

// Check if stack is empty
int isEmpty(struct MyStack *stack) {
    if (stack != NULL && stack->size > 0 && stack->top != NULL) {
        return 0;
    } else {
        return 1;
    }
}

// Return top element of stack
struct StackNode *peek(struct MyStack *stack) {
    if (isEmpty(stack)) return NULL;
    return stack->top;
}

// Create a new node of stack
struct StackNode *newNode(int disk, int source, int destination, int auxiliary) {
    struct StackNode *node = (struct StackNode *)malloc(sizeof(struct StackNode));
    if (node != NULL) {
        node->disk = disk;
        node->source = source;
        node->destination = destination;
        node->auxiliary = auxiliary;
        node->next = NULL;
    }
    return node;
}

// Add node at the top of stack
void push(struct MyStack *stack, struct StackNode *node) {
    if (stack == NULL || node == NULL) return;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

// Remove top element of stack
void pop(struct MyStack *stack) {
    if (isEmpty(stack)) return;
    struct StackNode *temp = stack->top;
    stack->top = stack->top->next;
    stack->size--;
    free(temp);
}

// Iterative Tower of Hanoi using the custom stack
void towerOfHanoi(int n, char src, char dest, char aux) {
    struct MyStack *stack = newStack();
    if (stack == NULL) return;

    // Push the initial full problem onto the stack
    push(stack, newNode(n, src, dest, aux));

    while (!isEmpty(stack)) {
        struct StackNode *curr = peek(stack);
        
        int disk = curr->disk;
        int source = curr->source;
        int destination = curr->destination;
        int auxiliary = curr->auxiliary;
        
        // Pop the current element as we have captured its data
        pop(stack);

        if (disk < 0) {
            // Negative disk indicates a specific resolved single-disk move command
            printf("Move disk %d from tower [%c] to [%c]\n", -disk, source, destination);
        } else if (disk == 1) {
            // Base case: move disk 1 directly
            printf("Move disk 1 from tower [%c] to [%c]\n", source, destination);
        } else {
            // Decompose the problem into 3 steps and push in reverse order (LIFO)
            
            // 3. Move n-1 disks from auxiliary to destination
            push(stack, newNode(disk - 1, auxiliary, destination, source));
            
            // 2. Move the nth disk from source to destination (marked negative to print immediately later)
            push(stack, newNode(-disk, source, destination, auxiliary));
            
            // 1. Move n-1 disks from source to auxiliary
            push(stack, newNode(disk - 1, source, auxiliary, destination));
        }
    }
    
    free(stack);
}

int main() {
    int n;
    printf("no of disks: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    // Solve Tower of Hanoi for n disks from peg 'A' to 'C' using 'B'
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}
