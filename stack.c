#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char *value;
    struct node *next;
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

void push(stack_t *s, char *value);
void pop(stack_t *s);
char *peek(stack_t *s);

int main(void)
{
    stack_t s = createStack();
    push(&s, "HI");
    push(&s, "HI2");
    pop(&s);
    char *res = peek(&s);
    printf("%s\n", res);
}

void push(stack_t *s, char *value)
{
    node_t *newNode = malloc(sizeof(node_t));
    char *memorySpace = malloc(strlen(value) + 1);
    memorySpace = value;
    newNode->value = memorySpace;
    newNode->next = s->top;
    if (!s->top)
    {
        s->bottom = newNode;
        s->top = s->bottom;
        return;
    }
    s->top = newNode;
    s->length++;
    return;
}

void pop(stack_t *s)
{
    if (s->length >= 0)
    {
        node_t *hasToGo = s->top;
        free(s->top->value);
        s->top = s->top->next;
        free(hasToGo);
        s->length--;
        return;
    }
    return;
}

char *peek(stack_t *s)
{
    if (s->top)
    {
        return s->top->value;
    }
    return (char *)-1;
}
