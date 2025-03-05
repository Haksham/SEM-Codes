// Q.3 c program to simulate a calculator reading the operation and operands from command line.

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <operand1> <op> <operand2>\n", argv[0]);
        return 1;
    }
    double operand1 = atof(argv[1]);
    char op = argv[2][0];
    double operand2 = atof(argv[3]);
    double res;

    switch (op) {
        case '+':
            res = operand1 + operand2;
            break;
        case '-':
            res = operand1 - operand2;
            break;
        case '*':
            res = operand1 * operand2;
            break;
        case '/':
            if (operand2 == 0) {
                fprintf(stderr, "Error: Division by zero\n");
                return 1;
            }
            res = operand1 / operand2;
            break;
        default:
            fprintf(stderr, "Error: Invalid op '%c'\n", op);
            return 1;
    }
    printf("res: %f\n", res);
    return 0;
}

// To Run: gcc -o calc calculator(3).c -> ./calc 5 + 3