#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;
void push(int data) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Stack Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack.\n", data);
}
void pop() 
{
    if (top == NULL) 
    {
        printf("Stack Underflow! No element to pop.\n");
        return;
    }
    struct Node *temp = top;
    printf("Popped element: %d\n", top->data);
    top = top->next;
    free(temp);
}
void display() 
{
    if (top == NULL) 
    {
        printf("Stack is empty.\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main() 
{
    int choice, data;
    while (1) 
    {
        printf("\n*** Stack Menu ***\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) 
        {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}