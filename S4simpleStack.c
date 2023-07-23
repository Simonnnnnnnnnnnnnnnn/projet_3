/**
 * [INGInious] url for submitting : https://inginious.info.ucl.ac.be/course/LEPL1503/s4_simple_stack
 *
 *  you just need to provide pop/push functions inside this module
 *
 *  for testing purpose here, we created a main function that takes all the arguments received and use push for each
 *  then we pop. after each action we print the stack.
 *
 * build this via gcc or IDE
 * in a console/terminal, you can call the program using the following command
 *          .\S4SimpleStack.exe arg1 arg2 whatEverYouWant "Frankly, what ever your you want"
 *
 */
#include<stdlib.h>
#include <stdio.h>
#include<string.h>

struct node {
    struct node *next;
    char *name;
};

/**
* Remove the top element of the node and return its content.
*
* @head : pointer to the top of the node
* @result : pointer to store the popped element
*
* @return 0 if no error, 1 otherwise
*
* pre : @result contains a null-terminated correct string
* post : @result contains the string @name from the element at the top of the node
*/

int pop(struct node **head, char *result) {
    if (head == NULL || *head == NULL) { return 1; }
    strcpy(result, (*head)->name);
    if (result != NULL) {
        struct node *top = *head;
        *head = (*head)->next;
        free(top->name);
        free(top);
        return 0;
    }
    return 1;
}

/**
* Add @name at the "top" of the node.
*
* @head : pointer to the top of the node
* @name : the string to be placed in the element at the top of the node
*
* @return 0 if no error, 1 otherwise
*/

int push(struct node **head, const char *value) {
    if (head == NULL) { return 1; }
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL) { return 1; }
    newNode->name = (char *) malloc(sizeof(char) * strlen(value) + 1);
    strcpy(newNode->name, value);
    newNode->next = *head;
    *head = newNode;
    return 0;
}

//function for printing value stored in the node
void printStack(struct node *head) {
    if (head == NULL) {
        printf("\nStack at address[%p] is empty!", head);
    } else {
        printf("\nat address[%p]: \n\t", head);

        while (head != NULL) {
            printf("{ .name: \"%s\", .next: [%p]%s\n\t",
                   head->name,
                   head->next,
                   (head->next == NULL ? "(NULL) }" : " } --> ")
            );
            head = head->next;
        }
    }
}

int main(int argc, char **argv) {
    struct node *head = NULL; // malloc(sizeof(struct node));
    for (int i = 0; i < argc; i++) {
        printf("\n<::>>> push(&head, , *(argv + i)) with *(argv + i)= \"%s\"...\n", *(argv + i));
        push(&head, *(argv + i));
        printStack(head);
    }

    for (int i = 0; i <= argc; i++) {
        const char* name=(char*)malloc(sizeof(char)*50);
        if(pop(&head, name)==0) {
            printf("\n<::>>> pop(&head, name) = 0 with name= \"%s\"\n", name);
        } else {
            printf("\n<::>>> pop(&head, name) = 1\n");
        }
        printStack(head);
        free(name);
    }
}
