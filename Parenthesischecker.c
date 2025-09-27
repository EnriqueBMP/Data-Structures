#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

int isBalanced(const char *expr) {
    for (int i = 0; i < strlen(expr); i++) {
        char c = expr[i];

        if (c == '(' || c == '[' || c == '{') {
            push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) {
                return 0;
            }

            char topChar = pop();
            if (!isMatchingPair(topChar, c)) {
                return 0;
            }
        }
    }

    return top == -1;
}

int main() {
    char expression[MAX];

    printf("Enter an expression with parentheses: ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = '\0';

    if (isBalanced(expression)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is NOT balanced.\n");
    }

    return 0;
}
