#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char devices[20];
    int data;
    struct Node* next;
};

struct Node* myNode(char* devices, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    printf(newNode->devices, sizeof(newNode->devices), "%s", devices);
    newNode->next = NULL;
    return newNode;
}

void insertion(struct Node** head, char* device, int data) {
    struct Node* newNode = myNode(device, data);
    if (*head == NULL || (*head)->data > data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL && current->next->data <= data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void process(struct Node** head) {
    if (*head == NULL) {
        printf("No requests to process.\n");
        return;
    }
    struct Node* temp = *head;
    printf("Processing: %s with priority %d\n", temp->devices, temp->data);
    *head = (*head)->next;
    free(temp);
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("Device: %s, Priority: %d\n", head->devices, head->data);
        head = head->next;
    }
}

int main() {
    int devicePriority[4] = {1, 2, 3, 4};
    struct Node* pq = NULL;
    insertion(&pq, "Keyboard"  ,devicePriority[0]);
    insertion(&pq, "Mouse" ,devicePriority[1]);
    insertion(&pq, "Scanner" ,devicePriority[2]);
    insertion(&pq, "Printer" ,devicePriority[3]);
    printf("Priority Queue:\n");
    display(pq);
    printf("\nProcessing requests:\n");
    process(&pq);
    process(&pq);
    printf("\n Remaining Queue:\n");
    display(pq);
    return 0;
}
