#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int evaluate_postfix(char *exp) {
    int stack[MAX];
    int top = -1;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            stack[++top] = exp[i] - '0';
        } else {
            int val2 = stack[top--];
            int val1 = stack[top--];
            switch (exp[i]) {
                case '+': stack[++top] = val1 + val2; break;
                case '-': stack[++top] = val1 - val2; break;
                case '*': stack[++top] = val1 * val2; break;
                case '/': stack[++top] = val1 / val2; break;
            }
        }
    }
    return stack[top];
}

int main() {
    char exp[] = "53+82-*";
    int result = evaluate_postfix(exp);
    printf("Postfix expression: %s\n", exp);
    printf("Evaluation result: %d\n", result);
    return 0;
}
