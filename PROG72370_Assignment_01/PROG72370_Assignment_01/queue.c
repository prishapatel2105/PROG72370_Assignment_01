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