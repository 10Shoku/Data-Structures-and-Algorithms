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

void push(char *stack, int *tos, char data) {
    stack[++(*tos)] = data;
}

void pop(char *stack, int *tos) {
    if (isEmpty(*tos)) {
        printf("Stack is empty\n");
        return;
    }

    stack[(*tos)--];
}

char top(char *stack, int tos) {
    if (isEmpty(tos)) {
        printf("Stack is empty\n");
        return 'x';
    }

    return stack[tos];
}

void traverse (char *stack, int tos) {
    if (isEmpty(tos)) {
        printf("Stack is empty\n");
        return;
    }

    for (int i = 0; i <= tos; i++)
        printf("%c", stack[i]);

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
            push(optr.stk, &optr.tos, sc);

        else if (sc >= 'A' && sc <= 'Z')
            push(post.stk, &post.tos, sc);

        else if (sc == ')') {
            while (optr.stk[optr.tos] != '(') {
                push(post.stk, &post.tos, optr.stk[optr.tos]);
                pop(optr.stk, &optr.tos);
            }

            pop(optr.stk, &optr.tos); // remove the '('
        }

        else {
            while (!isEmpty(optr.tos) && precedence(sc) <= precedence(optr.stk[optr.tos])) {
                push(post.stk, &post.tos, optr.stk[optr.tos]);
                pop(optr.stk, &optr.tos);
            }

            push(optr.stk, &optr.tos, sc);
        }
    }

    while (!isEmpty(optr.tos)) {
        push(post.stk, &post.tos, optr.stk[optr.tos]);
        pop(optr.stk, &optr.tos);
    }

    traverse(post.stk, post.tos);
}