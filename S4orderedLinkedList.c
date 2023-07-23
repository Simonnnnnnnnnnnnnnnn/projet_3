/**
 * [INGInious] url for submitting : https://inginious.info.ucl.ac.be/course/LEPL1503/s4_simple_stack
 *
 *  you just need to provide compare & insert functions inside this module
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
#include<stdio.h>
#include<string.h>

typedef struct node {
    char val;
    struct node *next;
} node_t;

/*
* @return: 0 if equals, negative number if @b is greater,
* and positive number otherwise
*/
int compare(char a, char b) {
    return (int) a - (int) b;
}

/*
* @value: value to be inserted. If the value is already in the list, no element is added and the list is not modified
* @fun: comparison function which defines the order relationship of the list
* @head: first node of the list, head != NULL
* @return: 0 if success, -1 otherwise
*/
int insert(node_t **head, char val, int (*cmp)(char, char)) {
    if (*head == NULL) {
        *head = (node_t *) malloc(sizeof(node_t));
        if (*head == NULL) { return -1; }
        (*head)->val = val;
        (*head)->next = NULL;
        return 0;
    }
    node_t *current = *head;
    node_t *previous = NULL;
    while (current != NULL && cmp(val, current->val) > 0) {
        previous = current;
        current = current->next;
    }
    if (current != NULL && current->val == val) {
        return 0;
    }
    node_t *newNode = (node_t *) malloc(sizeof(node_t));
    if (newNode == NULL) { return -1; }
    newNode->val = val;
    newNode->next = current;
    if (previous == NULL) {
        *head = newNode;
    } else {
        previous->next = newNode;
    }
    return 0;
}

//function for printing value stored in the node
void printStack(node_t *head) {
    if (head == NULL) {
        printf("\nNo node!");
    } else {
        printf("\nat address[%p]: \n\t", head);

        while (head != NULL) {
            printf("{ .val: '%c', .next: [%p]%s\n\t",
                   head->val,
                   head->next,
                   (head->next == NULL ? "(NULL) }" : " } --> ")
            );
            head = head->next;
        }
    }
}

int removeNode(node_t **head, char val, int (*cmp)(char, char)) {
    if (*head == NULL) { return -1; }
    node_t *current = *head;
    node_t *previous = NULL;
    while (current != NULL && cmp(val, current->val) > 0) {
        previous = current;
        current = current->next;
    }
    if (current != NULL && current->val == val) {
        // found val!
        node_t *temp = current;
        if (previous == NULL) {
            previous = *head;
        }
        if (current == *head) {
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        free(temp);
        return 0;
    }
    return 0;
}

int main(int argc, char **argv) {
    struct node *head = NULL; // malloc(sizeof(struct node));
    char *string = *(argv + 1);
    printf("::inserting each letter from \"%s\"", string);
    for (int i = 0; i < strlen(string); i++) {
        printf("\n::>>>insert(&head, string[i], &compare) with string[i]= '%c'...\n", string[i]);
        insert(&head, string[i], &compare);
        printStack(head);
    }
    const char *charactersToRemove = "gta, just a game?";
    printf("::removing each letter from \"%s\"", charactersToRemove);
    for (int i = 0; i < strlen(charactersToRemove); i++) {
        printf("\n::>>>removeNode(&head, '%c', &compare)...\n", charactersToRemove[i]);
        removeNode(&head, charactersToRemove[i], &compare);
        printStack(head);
    }
}
