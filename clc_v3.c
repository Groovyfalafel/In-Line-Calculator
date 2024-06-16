#include <stdio.h>
#include <math.h>
#include <ctype.h>

char displayMainMenu();
void performBinaryOperation();
void performUnaryOperation(float memory[]);
void defineVariables(float memory[]);
void performAdvancedOperation(float memory[]);
void performAdvancedBinaryOperation(float memory[]);
void performAdvancedUnaryOperation(float memory[]);
void displayOptions();
float calculateBinaryOperation(float num1, float num2, char op);
float calculateUnaryOperation(float num, char op);

int main() {
    char option;
    float memory[5] = {0};

    printf("Welcome to my Command-Line Calculator (CLC)\n");
    printf("Developer: Anas\nVersion: Assignment 2\nDate: 17th November 2023\n");
    
    do {
        option = displayMainMenu();
        switch (option) {
            case 'B':
                performBinaryOperation();
                break;
            case 'U':
                performUnaryOperation(memory);
                break;
            case 'V':
                defineVariables(memory);
                break;
            case 'A':
                performAdvancedOperation(memory);
                break;
            case 'E':
                printf("\nThanks for using my Simple Calculator. Hope to see you soon again. Goodbye!\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while (option != 'E');

    return 0;
}

char displayMainMenu() {
    char option;
    displayOptions();
    printf("Please select an option: ");
    scanf(" %c", &option);
    getchar(); 

    option = toupper((unsigned char)option);

    while (option != 'B' && option != 'U' && option != 'V' && option != 'A' && option != 'E') {
        printf("Invalid option. Please try again: ");
        scanf(" %c", &option);
        getchar(); // Consume the newline character
    }

    return option; 
}

void displayOptions() {
    printf("Options:\n");
    printf("- B: Binary Mathematical Operations\n");
    printf("- U: Unary Mathematical Operations\n");
    printf("- V: Define Variables\n");
    printf("- A: Advanced Mathematical Operations\n");
    printf("- E: Exit\n");
}

void performBinaryOperation() {
    char op;
    float num1, num2;

    printf("Enter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);
    printf("Enter your operation (+, -, *, /, %%, P, X, I): ");
    scanf(" %c", &op);

    float result = calculateBinaryOperation(num1, num2, op);
    if (result != 0.0 || op == '+' || op == '-' || op == '*' || (op == '/' && num2 != 0)) {
        printf("The result is: %f\n", result);
    }
}

float calculateBinaryOperation(float num1, float num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
                return 0.0;
            }
            return num1 / num2;
        case '%':
            if ((int)num2 == 0) { 
                printf("Error: Modulo by zero\n");
                return 0.0;
            }
            return fmod(num1, num2);
        case 'P':
            return pow(num1, num2);
        case 'X':
            return fmax(num1, num2);
        case 'I':
            return fmin(num1, num2);
        default:
            printf("Invalid operator\n");
            return 0.0;
    }
}

void performUnaryOperation(float memory[]) {
    
}

void defineVariables(float memory[]) {
   
}

void performAdvancedOperation(float memory[]) {
    
}

void performAdvancedBinaryOperation(float memory[]) {
   
}

void performAdvancedUnaryOperation(float memory[]) {
    
}

float calculateUnaryOperation(float num, char op) {
    switch (op) {
        case 'S':
            return sqrt(num);
        case 'L':
            return log(num);
        case 'E':
            return exp(num);
        case 'C':
            return cos(num);
        case 'F':
            return floor(num);
        default:
            printf("Invalid operator\n");
            return 0.0;
    }
}