#include <stdio.h>

typedef struct Node
{
    char *value;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node top;
    Node bottom;
    int length;
} Stack;

Stack createStack()
{
    Stack stack = {NULL, NULL, 0};
    return stack;
}

void push(char *value, Stack *stack);
void peek(Stack *stack);
void isEmpty(Stack *stack);
void pop(Stack *stack);

int main(void)
{
    Stack stack = createStack();
    push("HI", &stack);
    push("HI2", &stack);
    push("HI3", &stack);
    pop(&stack);
    pop(&stack);
    peek(&stack);
}

void push(char *value, Stack *stack)
{
    if (stack->top.value == NULL)
    {
        stack->bottom.value = value;
        stack->bottom.next = NULL;
        stack->top = (*stack).bottom;
        return;
    }
    Node newNode;
    newNode.value = value;
    Node currentTop = {stack->top.value, stack->top.next};
    newNode.next = &currentTop;
    stack->top = newNode;
    stack->length++;
    return;
}

void peek(Stack *stack)
{
    if (stack->length >= 0)
    {
        printf("%s\n", stack->top.value);
        return;
    }
    printf("NULL\n");
}

void pop(Stack *stack)
{
    if (stack->length > 0)
    {
        stack->length--;
        stack->top = *stack->top.next;
        return;
    }
    else
    {
        stack->bottom.value = NULL;
        stack->bottom.next = NULL;
        stack->top.next = NULL;
        stack->top.value = NULL;
        return;
    }
    printf("NULL\n");
}