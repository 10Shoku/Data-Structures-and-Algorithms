#include <stdio.h>

typedef struct {
    char stk[100];
    int tos;
} stack;

int isEmpty(int tos) {
    if (tos == -1) {
        return 1;
    }

    return 0;
}

void push(stack *s, char data) {
    s->stk[++s->tos] = data;
}

void pop(stack *s) {
    if (isEmpty(s->tos)) {
        printf("Stack is empty\n");
        return;
    }

    s->tos--;
}

char top(stack *s) {
    if (isEmpty(s->tos)) {
        printf("Stack is empty\n");
        return 'x';
    }

    return s->stk[s->tos];
}

void traverse (stack *s) {
    if (isEmpty(s->tos)) {
        printf("Stack is empty\n");
        return;
    }

    for (int i = 0; i <= s->tos; i++)
        printf("%c", s->stk[i]);

    printf("\n");
}

int precedence(char ch) {
    if (ch == '$') return 3;
    else if (ch == '/' || ch == '*') return 2;
    else if (ch == '+' || ch == '-') return 1;
    else return 0;
}

int main() {
    stack post, optr;
    post.tos = optr.tos = -1;

    const char expn[] = "A+(((B-C)*(D-E)+F)/G)$(H-I)";
    int size = sizeof(expn) / sizeof(expn[0]);

    int sc; // scanned character

    for (int i = 0; i < size; i++) {
        sc = expn[i];

        if (sc == '(')
            push(&optr, sc);

        else if (sc >= 'A' && sc <= 'Z')
            push(&post, sc);

        else if (sc == ')') {
            while (top(&optr) != '(') {
                push(&post, top(&optr));
                pop(&optr);
            }

            pop(&optr); // remove the '('
        }

        else {
            while (!isEmpty(optr.tos) && precedence(sc) <= precedence(top(&optr))) {
                push(&post, top(&optr));
                pop(&optr);
            }

            push(&optr, sc);
        }
    }

    while (!isEmpty(optr.tos)) {
        push(&post, top(&optr));
        pop(&optr);
    }

    traverse(&post);
}
