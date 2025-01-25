#include <stdio.h>
#include "queue.h"

typedef struct {
    Queue q;
    int pushIterations;
    int totalOperations;
} Stack;

void init(Stack* stack) {
    initializeQueue(&stack->q);
    stack->pushIterations = 0;
    stack->totalOperations = 0;
}

void push(Stack* stack, int x) {
    if (is_full(&stack->q)) {
        printf("Stack Overflow\n");
        return;
    }

    // Enqueue the new element
    enqueue(&stack->q, x);

    // Rotate queue to bring new element to front
    int size = stack->q.rear;
    stack->pushIterations += size - 1;
    stack->totalOperations++;

    for (int i = 1; i < size; i++) {
        int front = dequeue(&stack->q);
        enqueue(&stack->q, front);
    }
}

int pop(Stack* stack) {
    if (is_empty(&stack->q)) {
        printf("Stack Underflow\n");
        return -1;
    }
    stack->totalOperations++;
    return dequeue(&stack->q);
}

int top(Stack* stack) {
    if (is_empty(&stack->q)) {
        printf("Stack is empty\n");
        return -1;
    }
    return peek(&stack->q);
}

int empty(Stack* stack) {
    return is_empty(&stack->q);
}

void printStats(Stack* stack) {
    printf("Single Queue Stack Stats:\n");
    printf("Push Iterations: %d\n", stack->pushIterations);
    printf("Total Operations: %d\n", stack->totalOperations);
}

int main(void) {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printStats(&s);

    int a = pop(&s);
    push(&s, 40);

    printStats(&s);
    return 0;
}
