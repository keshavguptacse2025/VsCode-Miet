#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;
    int exp;
    struct Term *next;
};

struct Term *create_term(int coeff, int exp) {
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}

void append_term(struct Term **poly, int coeff, int exp) {
    struct Term *newTerm = create_term(coeff, exp);
    if (*poly == NULL) {
        *poly = newTerm;
        return;
    }
    struct Term *curr = *poly;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newTerm;
}

void display_polynomial(struct Term *poly) {
    struct Term *curr = poly;
    while (curr != NULL) {
        printf("%dx^%d", curr->coeff, curr->exp);
        curr = curr->next;
        if (curr != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Term *poly = NULL;
    append_term(&poly, 5, 3);
    append_term(&poly, 4, 2);
    append_term(&poly, 2, 0);
    printf("Polynomial representation: ");
    display_polynomial(poly);
    return 0;
}
