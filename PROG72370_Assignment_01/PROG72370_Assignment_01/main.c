#include <stdio.h>
#include "queue.h"

int main()
{
	Queue q; // Declare a variable of type Queue to represent the queue data structure
	initializeQueue(&q); // Call the function to initialize the queue, passing a pointer to the queue variable, which sets the head and tail pointers to NULL, indicating an empty queue

	User u = { "testUser", 10, "Red" }; // Create a User structure variable named u and initialize it with the username "testUser", level 10, and faction "Red"
	enqueue(&q, u); // Call the function to add the user u to the back of the queue, passing a pointer to the queue variable and the user variable as arguments; this will create a new node in the queue with the user information and link it to the end of the queue

	User out; // Declare a variable of type User named out to store the user information that will be removed from the front of the queue
	dequeue(&q, &out); // Call the function to remove a user from the front of the queue, passing a pointer to the queue variable and a pointer to the out variable as arguments; this will copy the user information from the head node of the queue into the out variable and update the head pointer to point to the next node in the queue

	printf("%s\n", out.username); // Print the username of the user stored in the out variable to the console, which should output "testUser" as it was the user that was enqueued and then dequeued from the queue

    return 0;
}