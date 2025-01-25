#include <stdio.h>
#include "list.h"

void reverseDoubleList(Node** head)
{
    if (*head == NULL || getNext(*head) == NULL) {
        return; // Empty or single-element list is already reversed
    }

    Node* current = *head;
    Node* temp = NULL;

    // Swap next and prev pointers for each node
    while (current != NULL) {
        // Swap the next and prev pointers
        temp = getPrev(current);
        setPrev(current, getNext(current));
        setNext(current ,temp);

        // Move to the next node
        current = getPrev(current);
    }

    // Update the head to the last node (which is now the first)
    if (temp != NULL) {
        *head = getPrev(temp);
    }
}

void appendDoubleList(Node** head, int value)
{
    Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (getNext(current) != NULL) {
        current = getNext(current);
    }

    setNext(current, newNode);
    setPrev(newNode, current);
}

void display(Node** head)
{
    Node* current = *head;
    while (current != NULL) {
        printf("%d -> ", getValue(current));
        current = getNext(current);
    }
    printf("NULL\n");
}

int main(void)
{
    Node* head = NULL;
    appendDoubleList(&head, 10);
    appendDoubleList(&head, 13);
    appendDoubleList(&head, 66);
    appendDoubleList(&head, 14);
    appendDoubleList(&head, 25);
    appendDoubleList(&head, 20);
    appendDoubleList(&head, 75);

    printf("Original List : \n");
    display(&head);

    reverseDoubleList(&head);

    printf("Reversed List : \n");
    display(&head);

    return 0;
}
