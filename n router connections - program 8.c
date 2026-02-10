#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 50

char istack[MAX];
int tos = -1;

float stack[MAX];
int top = -1;

/* ---------- Operator Stack ---------- */

void ipush(char s) {
    if (tos == MAX - 1)
    {
        printf("Operator stack overflow\n");
        exit(1);
    }
    istack[++tos] = s;
}

char ipop() {
    if (tos == -1)
    {
        printf("Operator stack underflow\n");
        exit(1);
    }
    return istack[tos--];
}

int precd(char s) {
    switch (s)
    {
        case '^': return 4;
        case '*':
        case '%':
        case '/': return 3;
        case '+':
        case '-': return 2;
        case '(' : return 1;
    }
    return 0;
}

/* ---------- Infix to Postfix ---------- */

void convertip(char infix[], char postfix[]) {
    int i, j = 0;
    char symbol;

    ipush('(');
    strcat(infix, ")");

    for (i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];

        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        }
        else if (symbol == '(') {
            ipush(symbol);
        }
        else if (symbol == ')') {
            while (istack[tos] != '(')
                postfix[j++] = ipop();
            ipop();
        }
        else {
            while (precd(symbol) <= precd(istack[tos]))
                postfix[j++] = ipop();
            ipush(symbol);
        }
    }

    postfix[j] = '\0';
}

/* ---------- Operand Stack ---------- */

void push(float ele) {
    if (top == MAX - 1) {
        printf("Evaluation stack overflow\n");
        exit(1);
    }
    stack[++top] = ele;
}

float pop() {
    if (top == -1) {
        printf("Evaluation stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

/* ---------- Postfix Evaluation ---------- */

void evaluate(char postfix[]){
    float op1, op2, x;

    for (int i = 0; postfix[i] != '\0'; i++){
        char sym = postfix[i];

        if (isalpha(sym)) {
            printf("Enter value of %c: ", sym);
            scanf("%f", &x);
            push(x);
        }
        else {
            op2 = pop();
            op1 = pop();

            switch (sym){
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '%': push((int)op1 % (int)op2); break;
                case '^': push(pow(op1, op2)); break;
                default:
                    printf("Invalid postfix expression\n");
                    exit(1);
            }
        }
    }
    printf("Result = %.2f\n", pop());
}


int main(){
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    convertip(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    evaluate(postfix);
    return 0;
}
