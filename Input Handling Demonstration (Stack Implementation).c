#include <stdio.h>

int tos = -1;

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
    
    else {
        printf("Popped %d from the stack.\n\n", stack[tos]);
        tos--;
    }
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
    
    while (1) {
        printf("MENU\n----\n1) Push\n2) Pop\n3) Traverse\n4) Exit\n>>> ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid datatype.\n\n");
            while (getchar() != '\n');
        }

        else if (getchar() != '\n') {
            printf("\nInvalid input.\n\n");
            while (getchar() != '\n');
        }

        else
            break;
    }
    
    printf("\n");
    
    switch(choice) {
        case 1:
            printf("Enter data: ");
            
            if (scanf("%d", &data) != 1) {      // checks if input is an integer
                printf("\nInvalid datatype.\n\n");
                while (getchar() != '\n');      // clears input buffer
            }

            else if (getchar() != '\n') {       // checks if there are any extra characters. eg: 12abc
                printf("\nInvalid input.\n\n");
                while (getchar() != '\n');
            }

            else {
                printf("\n");
                push(stack, size, data);
            }

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
    int size;

    while (1) {
        printf("Stack Size: ");

        if (scanf("%d", &size) != 1) {
            printf("\nInvalid datatype.\n\n");
            while (getchar() != '\n');
        }

        else if (getchar() != '\n') {
            printf("\nInvalid input.\n\n");
            while (getchar() != '\n');
        }

        else
            break;
    }

    printf("\n");

    int stack[size];

    while (menu(stack, size));
}




/*
If you call scanf with the format string "%d %f %s", it will attempt to read an integer, 
a floating-point number, and a string. If it successfully reads all three items, it will return 3.

If scanf encounters an input failure (e.g., because the input is not a valid integer), 
it will return a value less than the number of items in the format string.
*/
