#include <stdio.h>
#include "queue.h"

int main()
{
	Queue q; // Declare a variable of type Queue to represent the queue
	initializeQueue(&q); // Initialize the queue by calling the initializeQueue function, passing the address of the queue variable

	if (isEmpty(&q)) // Check if the queue is empty by calling the isEmpty function, passing the address of the queue variable
    {
		printf("Queue is empty\n"); // If the queue is empty, print a message indicating that the queue is empty
    }

    return 0;
}