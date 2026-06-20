#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

int main(int argc, char* argv[]) // Main function that serves as the entry point of the program, which takes command-line arguments for the number of users to enqueue and processes the queue accordingly
{
	if (argc != 2) // Check if the correct number of command-line arguments is provided; if not, print usage instructions and return 1 to indicate an error
    {
		printf("Usage: ./program <numUsers>\n"); // Print usage instructions for the program, indicating that the user should provide the number of users to enqueue as a command-line argument
        return 1;
    }

	srand(time(NULL)); // Seed the random number generator with the current time to ensure that the random users generated in the queue are different each time the program is run

	Queue q; // Declare a Queue structure variable to represent the queue that will hold the users
	initializeQueue(&q); // Call the initializeQueue function to set up the queue by initializing its head and tail pointers to NULL, indicating that the queue is initially empty

	int num = atoi(argv[1]); // Convert the command-line argument for the number of users to enqueue from a string to an integer using the atoi function, and store it in the variable num

	enqueueRandomUsers(&q, num); // Call the enqueueRandomUsers function to generate and enqueue the specified number of random users into the queue by passing the queue pointer and the number of users as arguments

	User u; // Declare a User structure variable to hold the information of each user dequeued from the queue for processing and display

	while (!isEmpty(&q)) // Loop to process the queue until it is empty by checking if the queue is not empty using the isEmpty function, which returns 1 (true) if the queue is empty and 0 (false) otherwise
    {
		dequeue(&q, &u); // Call the dequeue function to remove a user from the front of the queue and store the user information in the User structure variable u by passing the queue pointer and the address of u as arguments

        printf("Username: %s Level: %d Faction: %s\n",
			u.username, u.level, u.faction); // Print the information of the dequeued user to the console in a formatted manner, displaying the username, level, and faction of the user
    }

    return 0;
}
