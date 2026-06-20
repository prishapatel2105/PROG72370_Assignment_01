#include "queue.h" // Include the header file for the Queue structure and function prototypes
#include <stdlib.h> // Include standard library for memory allocation

void initializeQueue(Queue* q) // Function to initialize the queue
{
	q->head = NULL; //  Set the head pointer to NULL, indicating an empty queue
	q->tail = NULL; // Set the tail pointer to NULL, indicating an empty queue
}

int isEmpty(Queue* q) // Function to check if the queue is empty
{
	return q->head == NULL; // Return 1 (true) if the head pointer is NULL, indicating the queue is empty; otherwise, return 0 (false)
}

int enqueue(Queue* q, User user) // Function to add a user to the back of the queue
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode)); // Allocate memory for a new node in the queue

	if (newNode == NULL) // Check if memory allocation was successful; if not, return 1 to indicate an error
		return 1; // If memory allocation fails, return 1 to indicate an error

	newNode->data = user; // Set the data field of the new node to the user information passed as an argument
	newNode->next = NULL; // Set the next pointer of the new node to NULL, as it will be the last node in the queue

	if (q->head == NULL) // Check if the queue is currently empty by checking if the head pointer is NULL
    {
		q->head = newNode; // If the queue is empty, set both the head and tail pointers to the new node, as it will be the only node in the queue
		q->tail = newNode; // Set the tail pointer to the new node, as it will be the only node in the queue
    }
    else
    {
		q->tail->next = newNode; // If the queue is not empty, set the next pointer of the current tail node to the new node, linking the new node to the end of the queue
		q->tail = newNode; // Update the tail pointer to point to the new node, as it is now the last node in the queue
    }

    return 0;
}