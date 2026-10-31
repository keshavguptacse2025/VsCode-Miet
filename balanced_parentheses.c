#include <stdio.h>
#include <string.h>

#define MAX 100

int is_matching_pair(char c1, char c2) {
    if (c1 == '(' && c2 == ')') return 1;
    if (c1 == '{' && c2 == '}') return 1;
    if (c1 == '[' && c2 == ']') return 1;
    return 0;
}

int is_balanced(char *exp) {
    char stack[MAX];
    int top = -1;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            stack[++top] = exp[i];
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) return 0;
            if (!is_matching_pair(stack[top--], exp[i])) {
                return 0;
            }
        }
    }
    return top == -1;
}

int main() {
    char exp1[] = "{[()]}";
    char exp2[] = "{[(])}";
    printf("%s is %s\n", exp1, is_balanced(exp1) ? "Balanced" : "Not Balanced");
    printf("%s is %s\n", exp2, is_balanced(exp2) ? "Balanced" : "Not Balanced");
    return 0;
}
