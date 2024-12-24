#include <stdio.h>

float balance = 0.0;

void deposit(float amount) {
    if (amount > 0) {
        balance = balance +amount;
        printf("Deposited: %.2f\n", amount);
    } else {
        printf("Invalid deposit amount\n");
    }
}

void withdraw(float amount) {
    if (amount > 0 && amount <= balance) {
        balance = balance -amount;
        printf("Withdrawn: %.2f\n", amount);
    } else if (amount > balance) {
        printf("Insufficient balance\n");
    } else {
        printf("Invalid withdrawal amount\n");
    }
}

void displayBalance() {
    printf("Current balance: %.2f\n", balance);
}

int main() {
    int choice;
    float amount;

    while (1) {
        printf("\nBank Account Menu:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Display Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the amount to deposit: ");
                scanf("%f", &amount);
                deposit(amount);
                break;
            case 2:
                printf("Enter the amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(amount);
                break;
            case 3:
                displayBalance();
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
