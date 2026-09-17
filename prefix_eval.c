#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow - Invalid Expression\n");
        exit(1);
    }
    return stack[top--];
}

int isOperator(char *token) {
    return (strlen(token) == 1 && strchr("+-*/^", token[0]) != NULL);
}

int applyOperator(int op1, int op2, char oper) {
    switch (oper) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/':
            if (op2 == 0) { printf("Error: Division by zero!\n"); exit(1); }
            return op1 / op2;
        case '^': return (int) pow(op1, op2);
        default:
            printf("Error: Invalid operator\n");
            exit(1);
    }
}

int evaluatePrefix(char *expr) {
    char tokens[MAX][10];
    int count = 0;

    char *token = strtok(expr, " ");
    while (token != NULL) {
        strcpy(tokens[count++], token);
        token = strtok(NULL, " ");
    }

    top = -1;

    for (int i = count - 1; i >= 0; i--) {
        if (isOperator(tokens[i])) {
            int op1 = pop();
            int op2 = pop();
            int result = applyOperator(op1, op2, tokens[i][0]);
            push(result);
        } else {
            push(atoi(tokens[i]));
        }
    }
    return pop();
}

int main() {
    char tests[6][MAX] = {
        "+ 9 * 2 6",
        "* + 2 3 4",
        "- * 4 5 3",
        "/ 20 4",
        "^ 2 3",
        "5"
    };

    for (int i = 0; i < 6; i++) {
        char expr[MAX];
        strcpy(expr, tests[i]);
        printf("Prefix Expression : %-15s -> Result: %d\n", tests[i], evaluatePrefix(expr));
    }
    return 0;
}
