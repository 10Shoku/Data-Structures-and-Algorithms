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

void reverse(char *stk, int tos) {
    char temp[100];

    for (int i = tos, j = 0; i > -1; i--, j++) {
        temp[j] = stk[i];
    }

    for (int i = 0; i <= tos; i++) {
        stk[i] = temp[i];
    }
}

int main() {
    stack pre, optr;
    pre.tos = optr.tos = -1;

    char expn[] = "(A+B*C$D)/((E+F-G)*H)$I/J";
    int size = sizeof(expn) / sizeof(expn[0]);

    int sc; // scanned character

    reverse(expn, size-1);

    for (int i = 0; i < size; i++) {
        sc = expn[i];

        if (sc == ')')
            push(&optr, sc);

        else if (sc >= 'A' && sc <= 'Z')
            push(&pre, sc);

        else if (sc == '(') {
            while (top(&optr) != ')') {
                push(&pre, top(&optr));
                pop(&optr);
            }

            pop(&optr);   // remove ')'
        }

        else {
            while (!isEmpty(optr.tos) && precedence(sc) < precedence(top(&optr))) {
                push(&pre, top(&optr));
                pop(&optr);
            }

            push(&optr, sc);
        }
    }

    while (!isEmpty(optr.tos)) {
        push(&pre, top(&optr));
        pop(&optr);
    }

    reverse(pre.stk, pre.tos);

    traverse(&pre);
}