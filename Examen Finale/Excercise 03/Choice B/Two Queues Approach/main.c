#include <stdio.h>
#include "queue.h"

typedef struct {
    Queue main_q;
    Queue aux_q;
    int pushIterations;
    int totalOperations;
} Stack;

void init(Stack* stack) {
    initializeQueue(&stack->main_q);
    initializeQueue(&stack->aux_q);
    stack->pushIterations = 0;
    stack->totalOperations = 0;
}

void push(Stack* stack, int x) {
    if (is_full(&stack->main_q) || is_full(&stack->aux_q)) {
        printf("Stack Overflow\n");
        return;
    }

    // Enqueue to auxiliary queue
    enqueue(&stack->aux_q, x);

    // Move all elements from main queue to auxiliary queue
    while (!is_empty(&stack->main_q)) {
        enqueue(&stack->aux_q, dequeue(&stack->main_q));
        stack->pushIterations++;
    }

    // Swap queues
    Queue temp = stack->main_q;
    stack->main_q = stack->aux_q;
    stack->aux_q = temp;

    stack->totalOperations++;
}

int pop(Stack* stack) {
    if (is_empty(&stack->main_q)) {
        printf("Stack Underflow\n");
        return -1;
    }
    stack->totalOperations++;
    return dequeue(&stack->main_q);
}

int top(Stack* stack) {
    if (is_empty(&stack->main_q)) {
        printf("Stack is empty\n");
        return -1;
    }
    return peek(&stack->main_q);
}

int empty(Stack* stack) {
    return is_empty(&stack->main_q);
}

void printStats(Stack* stack) {
    printf("Two Queue Stack Stats:\n");
    printf("Push Iterations: %d\n", stack->pushIterations);
    printf("Total Operations: %d\n", stack->totalOperations);
}

int main(void) {
    Stack stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printStats(&stack);
    return 0;
}
