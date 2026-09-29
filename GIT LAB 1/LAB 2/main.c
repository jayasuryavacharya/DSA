#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

/* Function for PUSH operation */
void push(char elem)
{
    stack[++top] = elem;
}

/* Function for POP operation */
char pop()
{
    return stack[top--];
}

/* Function for precedence */
int pr(char symbol)
{
    if (symbol == '^')
    {
        return 3;
    }
    else if (symbol == '*' || symbol == '/')
    {
        return 2;
    }
    else if (symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Main Program */
int main()
{
    char infix[SIZE], postfix[SIZE], ch, elem;
    int i = 0, k = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    push('#');

    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
        {
            push(ch);
        }
        else if (isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                postfix[k++] = pop();
            }

            elem = pop(); /* Remove '(' */
        }
        else
        {
            /* Operator */
            while (pr(stack[top]) >= pr(ch))
            {
                postfix[k++] = pop();
            }

            push(ch);
        }
    }

    /* Pop from stack till empty */
    while (stack[top] != '#')
    {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; /* Make postfix a valid string */

    printf("\nPostfix Expression = %s\n", postfix);

    return 0;
}

