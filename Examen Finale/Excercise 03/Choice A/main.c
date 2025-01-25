#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

// Operator precedence function
int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack operators;
    initStack(&operators);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If operand, add to postfix
        if (isdigit(c)) {
            postfix[j++] = c;
        }
        // If opening parenthesis, push to stack
        else if (c == '(') {
            push(&operators, c);
        }
        // If closing parenthesis, pop until matching opening parenthesis
        else if (c == ')') {
            while (!is_empty(&operators) && peek(&operators) != '(') {
                postfix[j++] = pop(&operators);
            }
            if (!is_empty(&operators) && peek(&operators) == '(') {
                pop(&operators);
            }
        }
        // If operator
        else {
            while (!is_empty(&operators) &&
                   precedence(peek(&operators)) >= precedence(c)) {
                postfix[j++] = pop(&operators);
            }
            push(&operators, c);
        }
    }

    // Pop remaining operators
    while (!is_empty(&operators)) {
        postfix[j++] = pop(&operators);
    }
    postfix[j] = '\0';
}

// Evaluate postfix expression
int evaluatePostfix(char* postfix) {
    Stack operands;
    initStack(&operands);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        // If digit, push to stack
        if (isdigit(c)) {
            push(&operands, c - '0');
        }
        // If operator, perform operation
        else {
            int b = pop(&operands);
            int a = pop(&operands);

            switch(c) {
                case '+':
                    push(&operands, a + b);
                    break;
                case '-':
                    push(&operands, a - b);
                    break;
                case '*':
                    push(&operands, a * b);
                    break;
                case '/':
                    push(&operands, a / b);
                    break;
            }
        }
    }

    return pop(&operands);
}

int main(void) {
    char infix[] = "(3+5)-7*9";
    char postfix[100];

    // Convert infix to postfix
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    // Evaluate postfix expression
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
