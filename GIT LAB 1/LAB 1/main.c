#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void push(int);
void pop(void);
void display(void);

int stack[SIZE];
int top = -1;

int main()
{
    int value, choice;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Wrong selection. Try again.\n");
        }
    }

    return 0;
}

void push(int value)
{
    if (top == SIZE - 1)
    {
        printf("Stack is full. Insertion is not possible.\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("Insertion successful.\n");
    }
}

void pop(void)
{
    if (top == -1)
    {
        printf("Stack is empty. Deletion is not possible.\n");
    }
    else
    {
        printf("Deleted %d\n", stack[top]);
        top--;
    }
}

void display(void)
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements are:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
