#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void insertAtPosK(Node** head, int value, int k)
{
    // Check for negative positions
    if (k < 0) {
        fprintf(stderr, "Error: Cannot insert at negative position\n");
        return;
    }

    // Create new node
    Node* newNode = createNode(value);

    // Case 1: Empty list or inserting at head
    if (*head == NULL || k == 0) {
        setNext(newNode, *head);
        *head = newNode;
        return;
    }

    // Traverse to find insertion point
    Node* current = *head;
    int position = 0;

    // Find the node before insertion point
    while (current != NULL && position < k - 1) {
        current = getNext(current);
        position++;
    }

    // Check if position is out of bounds
    if (current == NULL) {
        fprintf(stderr, "Error: Position %d is out of bounds\n", k);
        deleteNode(newNode);  // Free the newly created node
        return;
    }

    // Insert the new node
    setNext(newNode, getNext(current));
    setNext(current, newNode);
}

void display(Node** head)
{
    Node* current = *head;
    printf("\nYour Linked List: ");
    if (current == NULL) {
        printf("Empty\n");
        return;
    }

    while(current != NULL)
    {
        printf("%d -> ", getValue(current));
        current = getNext(current);
    }
    printf("NULL\n");
}

void clearList(Node** head)
{
    while(*head)
    {
        Node* temp = *head;
        *head = getNext(*head);
        deleteNode(temp);
    }
}

int main(void)
{
    Node* head = NULL;

    // Test Case 1: Insert into empty list
    printf("Test 1: Insert into empty list\n");
    insertAtPosK(&head, 10, 0);
    display(&head);

    // Test Case 2: Insert at head of non-empty list
    printf("\nTest 2: Insert at head\n");
    insertAtPosK(&head, -3, 0);
    display(&head);

    // Test Case 3: Insert in middle
    printf("\nTest 3: Insert in middle\n");
    insertAtPosK(&head, 26, 2);
    display(&head);

    // Test Case 4: Insert at end
    printf("\nTest 4: Insert at end\n");
    insertAtPosK(&head, 100, 3);
    display(&head);

    // Test Case 5: Out of bounds insertion
    printf("\nTest 5: Out of bounds insertion\n");
    insertAtPosK(&head, 55, 10);
    display(&head);

    // Test Case 6: Negative position
    printf("\nTest 6: Negative position\n");
    insertAtPosK(&head, 88, -1);
    display(&head);

    //Additional Element to Append The List
    printf("\nThe Final List : \n");
    insertAtPosK(&head, 20, 2);
    display(&head);

    // Clean up
    clearList(&head);

    return 0;
}
