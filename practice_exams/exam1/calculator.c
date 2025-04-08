#include <stdio.h>                      // Include standard input/output functions
#include <stdlib.h>                     // Include standard library functions (e.g., malloc, free, exit)
#include <string.h>                     // Include string manipulation functions (e.g., strlen)
#include <ctype.h>                      // Include character type functions (e.g., isdigit)
#include "linkedlist.h"                 // Include the header file for linked list functions (e.g., new_node, prepend, print_list, delete_list)

node* addition(node* num1, node* num2) {  // Function to add two numbers represented as linked lists
    node* result = NULL;                // Initialize the result linked list to NULL
    int carry = 0;                      // Initialize the carry variable to 0

    while (num1 != NULL || num2 != NULL || carry != 0) { // Loop while there is a digit in num1, num2, or a nonzero carry
        int sum = carry;               // Start sum with the current carry value

        if (num1 != NULL) {            // If there is a digit available in num1
            sum += num1->v;            // Add the value of the current node in num1 to sum
            num1 = num1->next;         // Advance num1 to the next node
        }
        if (num2 != NULL) {            // If there is a digit available in num2
            sum += num2->v;            // Add the value of the current node in num2 to sum
            num2 = num2->next;         // Advance num2 to the next node
        }

        carry = sum / 10;              // Compute the new carry by dividing sum by 10
        int digit = sum % 10;          // Compute the current digit (remainder of sum divided by 10)

        result = prepend(result, new_node(digit)); // Prepend a new node with the computed digit to the result linked list
    }
    return result;                     // Return the resulting linked list representing the sum
}

node* subtraction(node *num1, node *num2){ // Function to subtract num2 from num1, where both are represented as linked lists
    node *result = NULL;             // Initialize the result linked list to NULL
    int borrow = 0;                  // Initialize the borrow variable to 0
    while(num1 != NULL || num2 != NULL){ // Loop while there is a digit in num1 or num2
        int diff = borrow;           // Start diff with the current borrow value
        if(num1 != NULL){            // If there is a digit available in num1
            diff += num1->v;         // Add the value of the current node in num1 to diff
            num1 = num1->next;       // Advance num1 to the next node
        }
        if(num2 != NULL){            // If there is a digit available in num2
            diff -= num2->v;         // Subtract the value of the current node in num2 from diff
            num2 = num2->next;       // Advance num2 to the next node
        }
        if(diff < 0){                // If the computed diff is negative, a borrow is required
            diff += 10;              // Adjust diff by adding 10 to make it positive
            borrow = -1;             // Set borrow to -1 for the next iteration
        }
        else{
            borrow = 0;              // Otherwise, reset borrow to 0
        }
        result = prepend(result, new_node(diff)); // Prepend a new node with the computed diff to the result linked list
    }
    return result;                   // Return the resulting linked list representing the difference
}

node *remove_leading_zeros(node *num){ // Function to remove leading zeros from a number represented as a linked list
    node *temp = num;              // Create a temporary pointer to traverse the list, starting at the head
    while(temp != NULL && temp->v == 0){ // Loop while the current node is not NULL and its value is 0
        node *temp2 = temp;        // Store the current node in a temporary pointer for freeing
        temp = temp->next;         // Advance temp to the next node
        free(temp2);               // Free the memory of the node that contained a leading zero
    }
    return temp;                   // Return the updated linked list head after removing leading zeros
}

int main(int argc, char *argv[]){  // Main function: program entry point
    if(argc < 3){                // Check if there are at least 3 command-line arguments (program name, number1, number2)
        printf("Usage: ./sum number1 number2\n"); // Print usage message if insufficient arguments are provided
        exit(0);                 // Exit the program
    }
    node *num1 = NULL, *num2 = NULL; // Initialize linked list pointers for num1 and num2 to NULL
    node *sum = NULL;              // Initialize the pointer for the sum linked list to NULL
    node *difference = NULL;       // Initialize the pointer for the difference linked list to NULL

    for(int i = 0; i < strlen(argv[1]); i++){ // Loop through each character of the first command-line argument (number1)
        if(!isdigit(argv[1][i])){ // If the current character is not a digit
            printf("Invalid inputin number1\n"); // Print an error message for invalid input in number1
            exit(0);             // Exit the program
        }
        num1 = prepend(num1, new_node(argv[1][i] - '0')); // Convert the character to its numeric value and prepend it to the num1 list
    }
    for(int i = 0; i < strlen(argv[2]); i++){ // Loop through each character of the second command-line argument (number2)
        if(!isdigit(argv[2][i])){ // If the current character is not a digit
            printf("Invalid input in number2\n"); // Print an error message for invalid input in number2
            exit(0);             // Exit the program
        }
        num2 = prepend(num2, new_node(argv[2][i] - '0')); // Convert the character to its numeric value and prepend it to the num2 list
    }
    sum = addition(num1, num2);      // Call the addition function to compute the sum of num1 and num2, and store the result in sum
    difference = subtraction(num1, num2); // Call the subtraction function to compute the difference (num1 - num2), and store the result in difference

    sum = remove_leading_zeros(sum); // Remove any leading zeros from the sum linked list
    difference = remove_leading_zeros(difference); // Remove any leading zeros from the difference linked list
    
    print_list(sum);               // Print the linked list representing the sum
    print_list(difference);        // Print the linked list representing the difference

    delete_list(num1);             // Free the memory allocated for the num1 linked list
    delete_list(num2);             // Free the memory allocated for the num2 linked list
    delete_list(sum);              // Free the memory allocated for the sum linked list
    delete_list(difference);       // Free the memory allocated for the difference linked list
    return 0;                      // Return 0 to indicate successful program termination
}