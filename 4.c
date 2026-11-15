#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int val)
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = val;
}

int pop(int *success)
{
    if (top == -1) {
        *success = 0;
        return 0;
    }

    *success = 1;
    return stack[top--];
}

void display()
{
    int i;

    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack (top to bottom): ");
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

int main()
{
    int n, i, val, popped, success;

    printf("Enter number of elements to push (max %d): ", MAX);

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of elements\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);

        if (scanf("%d", &val) != 1) {
            printf("Invalid input\n");
            return 1;
        }

        push(val);
    }

    printf("\nBefore POP:\n");
    display();

    popped = pop(&success);

    if (success)
        printf("Popped element: %d\n", popped);
    else
        printf("Stack Underflow\n");

    printf("\nAfter POP:\n");
    display();

    return 0;
}
