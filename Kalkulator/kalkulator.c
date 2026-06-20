#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(char programName[]) {
    printf("Usage: %s number1 operation number2\n", programName);
    printf("Available operations:\n");
    printf("\tadd - addition\n");
    printf("\tsub - subtraction\n");
    printf("\tmul - multiplication\n");
    printf("\tdiv - division\n");
    printf("\tmod - modulo\n");
}

int main(int argc, char *argv[]) {
    int number1 = 0;
    int number2 = 0;
    int result = 0;
    float divisionResult = 0.0;

    if (argc != 4) {
        usage(argv[0]);
        return 1;
    }

    number1 = atoi(argv[1]);
    number2 = atoi(argv[3]);

    if (strcmp(argv[2], "add") == 0) {
        result = number1 + number2;
        printf("%d + %d = %d\n", number1, number2, result);
        return 0;
    }

    if (strcmp(argv[2], "sub") == 0) {
        result = number1 - number2;
        printf("%d - %d = %d\n", number1, number2, result);
        return 0;
    }

    if (strcmp(argv[2], "mul") == 0) {
        result = number1 * number2;
        printf("%d * %d = %d\n", number1, number2, result);
        return 0;
    }

    if (strcmp(argv[2], "div") == 0) {
        if (number2 == 0) {
            printf("Division by zero is not allowed.\n");
            return 1;
        }

        divisionResult = (float) number1 / number2;
        printf("%d / %d = %.2f\n", number1, number2, divisionResult);
        return 0;
    }

    if (strcmp(argv[2], "mod") == 0) {
        if (number2 == 0) {
            printf("Modulo by zero is not allowed.\n");
            return 1;
        }

        result = number1 % number2;
        printf("%d %% %d = %d\n", number1, number2, result);
        return 0;
    }

    usage(argv[0]);
    return 1;
}
