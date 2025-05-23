#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack 
{
    int top;
    char items[MAX];
};
void push(struct Stack *s, char c) 
{
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = c;
}
char pop(struct Stack *s) 
{
    if (s->top == -1)
        return '\0';
    return s->items[s->top--];
}
char peek(struct Stack *s) 
{
    if (s->top == -1)
        return '\0';
    return s->items[s->top];
}
int precedence(char c) 
{
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}
int isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
void infixToPostfix(char *infix, char *postfix) 
{
    struct Stack s;
    s.top = -1;
    int i = 0, j = 0;
    while (infix[i] != '\0') 
    {
        if (isalnum(infix[i])) 
        {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') 
        {
            push(&s, infix[i]);
        } else if (infix[i] == ')') 
        {
            while (s.top != -1 && peek(&s) != '(')
                postfix[j++] = pop(&s);
            pop(&s);
        } else if (isOperator(infix[i])) 
        {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(infix[i]))
                postfix[j++] = pop(&s);
            push(&s, infix[i]);
        }
        i++;
    }
    while (s.top != -1)
        postfix[j++] = pop(&s);

    postfix[j] = '\0';
}
int main() 
{
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
