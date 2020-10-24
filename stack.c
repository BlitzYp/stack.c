#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char *value;
    struct Node *next;
} node;

typedef struct Stack
{
    node *bottom;
    node *top;
    size_t length;
} stack;

stack createStack()
{
    stack s = {NULL, NULL, 0};
    return s;
}

void push(stack *s, char *value);
void pop(stack *s);
char *peek(stack *s);

int main(void)
{
  stack s = createStack();
  push(&s, "HI");
  push(&s, "HI2");
  pop(&s);
  char* res = peek(&s);
  printf("%s\n", res);
}

void push(stack *s, char *value)
{
    node *newNode = malloc(sizeof(node));
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
    s->length ++;
    return;
}

void pop(stack *s) 
{
    if (s->length >= 0) {
        node* hasToGo = s->top;
        free(s->top->value);
        s->top = s->top->next;
        free(hasToGo);
        s->length--;
        return;
    }
    return;
}

char *peek(stack *s)
{
    if (s->top)
    {
        return s->top->value;
    }
    return (char *)-1;
}
