#include <stdio.h>

int tos = -1;

/* 
todo: let user set stack size [done]
todo: fix error: entering char in choice causes infinite loop []
*/

int stackEmpty() {
    if (tos == -1)
        return 1;

    return 0;
}

int stackFull(int size) {
    if (tos == size-1)
        return 1;

    return 0;
}

void push(int stack[], int size, int data) {
    if (stackFull(size))
        printf("Stack is full.\n\n");

    else
        stack[++tos] = data;
}

void pop(int stack[]) {
    if (stackEmpty())
        printf("Stack is empty.\n\n");

    else
        tos--;
}

void traverse(int stack[]) {
    if (stackEmpty()) {
        printf("Stack is empty.\n\n");
        return;
    }

    for (int i = 0; i <= tos; i++) {
        printf("%d", stack[i]);

        if (i != tos)
            printf(", ");
    }

    printf("\n\n");
}

int menu(int stack[], int size) {
    int choice;
    int data;
    
    printf("MENU\n----\n1) Push\n2) Pop\n3) Traverse\n4) Exit\n>>> ");
    scanf("%d", &choice);
    printf("\n");
    
    switch(choice) {
        case 1:

            printf("Enter data: ");
            scanf("%d", &data);
            printf("\n");
            
            push(stack, size, data);
            break;
            
        case 2:
            pop(stack);
            break;
        
        case 3:
            traverse(stack);
            break;
        
        case 4:
            return 0;
            break;
        
        default:
            printf("Invalid choice.\n\n");
    }

    return 1;
}

int main() {
    printf("Stack Size: ");
    int size;
    scanf("%d", &size);

    int stack[size];
    
    while (menu(stack, size));
}