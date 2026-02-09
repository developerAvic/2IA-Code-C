#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
    char name;
};

// Stack operations
void push(struct Stack *s, int x) {
    s->arr[++(s->top)] = x;
}

int pop(struct Stack *s) {
    if (s->top == -1)
        return -1;
    return s->arr[(s->top)--];
}

int peek(struct Stack *s) {
    if (s->top == -1)
        return -1;
    return s->arr[s->top];
}

// Move disk between two rods
void moveDisk(struct Stack *src, struct Stack *dest) {
    int disk1 = pop(src);
    int disk2 = pop(dest);

    if (disk1 == -1) {
        push(src, disk2);
        printf("Move disk %d from %c to %c\n", disk2, dest->name, src->name);
    }
    else if (disk2 == -1) {
        push(dest, disk1);
        printf("Move disk %d from %c to %c\n", disk1, src->name, dest->name);
    }
    else if (disk1 > disk2) {
        push(src, disk1);
        push(src, disk2);
        printf("Move disk %d from %c to %c\n", disk2, dest->name, src->name);
    }
    else {
        push(dest, disk2);
        push(dest, disk1);
        printf("Move disk %d from %c to %c\n", disk1, src->name, dest->name);
    }
}

// Iterative Tower of Hanoi using stacks
void towerOfHanoi(int n, struct Stack *src, struct Stack *aux, struct Stack *dest) {
    int totalMoves = (1 << n) - 1;  // 2^n - 1

    // Swap destination and auxiliary for even disks
    if (n % 2 == 0) {
        struct Stack *temp = dest;
        dest = aux;
        aux = temp;
    }

    // Fill source stack
    for (int i = n; i >= 1; i--)
        push(src, i);

    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1)
            moveDisk(src, dest);
        else if (i % 3 == 2)
            moveDisk(src, aux);
        else
            moveDisk(aux, dest);
    }
}

int main() {
    int n;

    struct Stack src, aux, dest;

    src.top = aux.top = dest.top = -1;
    src.name = 'A';
    aux.name = 'B';
    dest.name = 'C';

    printf("Enter number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, &src, &aux, &dest);

    return 0;
}
