#include <stdio.h>
#include <stdlib.h>

int *a;
int max, top = -1;

void push(int ele)
{
    if (top == max - 1)    // stack full
    {
        max = max * 2;     // double the size
        a = realloc(a, max * sizeof(int));
        printf("Stack full. Resized to %d and element is pushed.\n", max);
    }

    a[++top] = ele;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -999;
    }

    return a[top--];
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int choice, ele;

    printf("Enter initial max size: ");
    scanf("%d", &max);

    a = (int *)malloc(max * sizeof(int));

    while (1)
    {
        printf("\nEnter choice:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &ele);
            push(ele);
            break;

        case 2:
            ele = pop();
            if (ele != -999)
                printf("Popped element = %d\n", ele);
            break;

        case 3:
            display();
            break;

        case 4:
            free(a);
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
