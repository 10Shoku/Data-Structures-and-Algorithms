/* 
0 to quit
1 to start push mode
2 to start poppin'
3 to traverse (stays in the same mode)
*/

#include <stdio.h>

void push(char *arr, int *tos, char data) {
    arr[++(*tos)] = data;
}

void pop(char *arr, int *tos) {
    if (*tos == -1) {
        printf("Empty stack\n\n");
        return;
    }

    printf("Popped %c\n\n", arr[(*tos)--]);
}

void traverse(char *arr, int *tos) {
    if (*tos == -1) {
        printf("Empty stack\n\n");
        return;
    }

    for (int i = 0; i <= *tos; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n\n");
}

int main() {
    char stack[100];
    int tos = -1;
    char ch;
    int flag = 0;

    while (1) {
        printf("> ");
        scanf(" %c", &ch);

        if (ch == '0') {
            printf("Quit");
            return 0;
        }

        else if (ch == '1') {
            printf("Push mode\n\n");
            flag = 1;
        }

        else if (ch == '2') {
            printf("Pop mode\n");
            pop(stack, &tos);
        }

        else if (ch == '3') {
            printf("Traverse\n");
            traverse(stack, &tos);
        }

        else {
            if (flag == 0) {
                printf("No modes selected\n");
            }
            else if (flag == 1) {
                push(stack, &tos, ch);
            }
        }
    }
}