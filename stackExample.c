//Implementation of node

#include <stdio.h>
#include<stdlib.h>

//declaring structure
struct node {
    int data;
    struct node *next; //pointer type of node
};

//typedef struct node Stack;
//typedef Stack *stackPtr;

//function prototypes of different functions
void push(struct node **head, int x); //for pushing value in node
int pop(struct node **head); //for popping value out of node
int isStackEmpty(struct node *head); //checking whether node is empty
void printStack(struct node *head); //for printing value that are pushed and popped
int convertValue(char *entry, int *value);

int main() {
    struct node *head = NULL; //declared pointer that points to the top of node
    int option; //variable for choosing different options
    char *value = (char *) malloc(sizeof(char) * 50); //variable for storing entered by the user
    int number;
    //different options for the user
    printf("\nFollowing options are available:\n");
    printf("\t\t1 (push)\n");
    printf("\t\t2 (pop)\n");
    printf("\t\t3 (Print)\n");
    printf("\t\t4 (exit)\n");
    printf("choose option: ");

    scanf("%d", &option);

    //program flow enters while loop if user enter value other than 3
    while (option != 4) {
        switch (option) {
            case 1:
                printf("\nEnter value: ");
                scanf("%s", value);
                if (convertValue(value, &number)) {
                    push(&head, number);
                } else {
                    printf("\"%s\" is not a number!", value);
                };
                break;

            case 2:
                if (!isStackEmpty(head)) {
                    printf("\nPopped Value: %d\n", pop(&head));
                }
                break;

            case 3:
                printStack(head);
                break;

            default:
                puts("\n**Invalid option [1 (push)| 2 (pop)| 3 (print)| 4 (exit)]**");
                break;
        }

        printf("\nchoose option: ");
        scanf("%d", &option);
    }
    free(value);
}

//function for pushing value into the top of node
void push(struct node **head, int x) {
    struct node* nodePtr;

    //allocating memory
    nodePtr = malloc(sizeof(struct node));

    //pushing value at the top of node only if there is space
    if (nodePtr != NULL) {
        nodePtr->data = x;
        nodePtr->next = *head;
        *head = nodePtr;
    } else
        printf("\nERROR !!! (Not enough space)");
}

//popping value out of the node
int pop(struct node **head) {
    int pValue; //variable for value at the top
    struct node* tempPtr; //temporary pointer

    tempPtr = *head;
    pValue = (*head)->data;
    *head = (*head)->next;
    free(tempPtr); //free temporary pointer value
    return pValue;
}

//function for printing value stored in the node
void printStack(struct node *head) {
    if (head == NULL) {
        printf("\nNo value found.");
    } else {
        printf("\nData stored in node:\n");

        while (head != NULL) {
            printf("%d --> ", head->data);
            head = head->next;
        }
        printf("NULL\n");
    }
}

int isStackEmpty(struct node *head) {
    return head == NULL;
}

int convertValue(char *entry, int *value) {
    char *p;
    *value = strtol(entry, &p, 10);
    return *p == '\0';
}