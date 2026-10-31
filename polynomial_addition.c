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
    if (coeff == 0) return;
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

struct Term *add_polynomials(struct Term *p1, struct Term *p2) {
    struct Term *res = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            append_term(&res, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            append_term(&res, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            append_term(&res, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        append_term(&res, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        append_term(&res, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return res;
}

void display_polynomial(struct Term *poly) {
    struct Term *curr = poly;
    while (curr != NULL) {
        printf("%dx^%d", curr->coeff, curr->exp);
        curr = curr->next;
        if (curr != NULL) printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Term *p1 = NULL;
    struct Term *p2 = NULL;
    append_term(&p1, 5, 2);
    append_term(&p1, 4, 1);
    append_term(&p1, 2, 0);

    append_term(&p2, 3, 3);
    append_term(&p2, 2, 2);
    append_term(&p2, 5, 0);

    printf("P1: ");
    display_polynomial(p1);
    printf("P2: ");
    display_polynomial(p2);

    struct Term *sum = add_polynomials(p1, p2);
    printf("P1 + P2: ");
    display_polynomial(sum);
    return 0;
}
