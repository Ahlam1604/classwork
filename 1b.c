#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack\n", data);
}

void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack from top to bottom:\n");
    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}

int main() {
    struct Node* stack = NULL;
    int Value;

    for (int i = 0; i < 5; i++) {
        printf("Enter the value to push onto the stack: ");
        scanf("%d", &Value);
        push(&stack, Value);

        printf("Stack after pushing %d:\n", Value);
        display(stack);
    }

    return 0;
}
