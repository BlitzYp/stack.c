#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char *value;
    struct Node *next;
} node_t;

typedef struct Stack
{
    node_t *bottom;
    node_t *top;
    size_t length;
} stack_t;

stack_t createStack()
{
    stack_t s = {NULL, NULL, 0};
    return s;
}

void push(stack_t *stack, char *value);
void pop(stack_t *stack);
char *peek(stack_t *stack);

int main(void)
{
    stack_t s = createStack();
    push(&s, "HI");
    push(&s, "HI2");
    push(&s, "HI3");
    pop(&s);
    char *res = peek(&s);
    printf("%s\n", res);
}

void push(stack_t *stack, char *value)
{
    node_t *newNode = malloc(sizeof(node_t));
    newNode->value = malloc(strlen(value) + 1);
    strcpy(newNode->value, value);
    if (!stack->bottom)
    {
        stack->bottom = newNode;
        stack->top = stack->bottom;
        return;
    }
    newNode->next = stack->top;
    stack->top = newNode;
    stack->length++;
    return;
}

void pop(stack_t *stack)
{
    if (!stack->length)
    {
        free(stack->bottom->value);
        free(stack->bottom);
        return;
    }
    free(stack->top->value);
    node_t *hasToGo = stack->top;
    stack->top = stack->top->next;
    free(hasToGo);
    stack->length--;
    return;
}

char *peek(stack_t *stack)
{
    return stack->length >= 0 ? stack->top->value : (char *)-1;
}
