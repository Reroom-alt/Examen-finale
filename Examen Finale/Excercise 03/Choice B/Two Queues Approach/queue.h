#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 5 // Size of the queue

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function declarations
void initializeQueue(Queue *q);
int is_empty(Queue *q);
int is_full(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int peek(Queue *q);

#endif
