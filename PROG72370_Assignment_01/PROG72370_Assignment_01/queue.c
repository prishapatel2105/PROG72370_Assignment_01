#include "queue.h" // Include the header file for the Queue structure and function prototypes
#include <stdlib.h> // Include standard library for memory allocation
#include <string.h>
#include <time.h>

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

int dequeue(Queue* q, User* user) // Function to remove a user from the front of the queue
{
	if (q->head == NULL) // Check if the queue is empty by checking if the head pointer is NULL
        return 1;

	QueueNode* temp = q->head; //	Store the current head node in a temporary variable to free its memory later
	*user = temp->data; // Copy the user information from the head node to the user pointer passed as an argument

	q->head = q->head->next; // Update the head pointer to point to the next node in the queue, effectively removing the current head node from the queue

	if (q->head == NULL) // Check if the queue is now empty after removing the head node
		q->tail = NULL; // If the queue is empty, set the tail pointer to NULL as well, indicating that the queue is now empty

	free(temp); // Free the memory allocated for the removed head node to prevent memory leaks

    return 0;
}

static void generateUsername(char name[])
{
    const char chars[] = "abcdefghijklmnopqrstuvwxyz0123456789";

    for (int i = 0; i < 10; i++)
        name[i] = chars[rand() % 36];

    name[10] = '\0';
}

int enqueueRandomUsers(Queue* q, int numUsers) // Function to add a specified number of random users to the back of the queue
{
	const char* factions[] = { "Red", "Blue", "Green" }; // Array of faction names to randomly assign to users

	for (int i = 0; i < numUsers; i++) // Loop to generate and enqueue the specified number of random users
    {
		User u; // Declare a User structure variable to hold the information of the user being generated

		generateUsername(u.username); // Generate a random username for the user and store it in the username field of the User structure
		u.level = (rand() % 60) + 1; // Generate a random level for the user between 1 and 60 (inclusive) and store it in the level field of the User structure
		strcpy_s(u.faction, sizeof(u.faction), factions[rand() % 3]); // Randomly select a faction from the factions array and copy it to the faction field of the User structure using a safe string copy function

		enqueue(q, u); // Enqueue the generated user into the queue by calling the enqueue function with the queue pointer and the User structure as arguments
    }

    return 0;
}