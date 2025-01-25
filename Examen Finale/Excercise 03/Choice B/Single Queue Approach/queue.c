#include <stdio.h>
#include "queue.h"

void initializeQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int is_empty(Queue *q) {
    return q->front == q->rear;
}

int is_full(Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        printf("Queue is full, cannot enqueue %d\n", value);
        return;
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_SIZE;
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return value;
}

int peek(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty, cannot peek\n");
        return -1;
    }
    return q->data[q->front];
}
