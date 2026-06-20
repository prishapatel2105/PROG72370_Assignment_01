#ifndef QUEUE_H
#define QUEUE_H

typedef struct User // Structure to represent a user in the queue
{
	char username[11]; // Username of the user, with a maximum length of 10 characters plus a null terminator
	int level; // Level of the user, represented as an integer
	char faction[10]; // Faction of the user, with a maximum length of 9 characters plus a null terminator
} User; // End of the User structure definition

typedef struct QueueNode // Structure to represent a node in the queue
{
	User data; // Data field to store the user information in the queue node
	struct QueueNode* next; // Pointer to the next node in the queue, allowing for linked list implementation of the queue
} QueueNode; // End of the QueueNode structure definition

typedef struct Queue // Structure to represent the queue itself
{
	QueueNode* head; //	Pointer to the head of the queue, representing the front of the queue
    QueueNode* tail; // Pointer to the tail of the queue, representing the back of the queue
} Queue;

void initializeQueue(Queue* q); // Function prototype for initializing the queue, which sets the head and tail pointers to NULL, indicating an empty queue
int isEmpty(Queue* q); // Function prototype for checking if the queue is empty, which returns 1 (true) if the head pointer is NULL, indicating the queue is empty; otherwise, it returns 0 (false)
int enqueue(Queue* q, User user);// Function prototype for adding a user to the back of the queue, which takes a pointer to the queue and a User structure as arguments, and returns 0 on success or 1 on failure (e.g., if memory allocation fails)
int dequeue(Queue* q, User* user); // Function prototype for removing a user from the front of the queue, which takes a pointer to the queue and a pointer to a User structure as arguments, and returns 0 on success or 1 if the queue is empty (i.e., if there are no users to dequeue)

#endif