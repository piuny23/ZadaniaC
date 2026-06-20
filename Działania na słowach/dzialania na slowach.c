#include <stdio.h>

#define TEXT_SIZE 80

void toLower(char text[]) {
    int i = 0;

    while (text[i] != '\0') {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = text[i] + ('a' - 'A');
        }

        i++;
    }
}

void toUpper(char text[]) {
    int i = 0;

    while (text[i] != '\0') {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = text[i] - ('a' - 'A');
        }

        i++;
    }
}

int textSize(char text[]) {
    int size = 0;

    while (text[size] != '\0') {
        size++;
    }

    return size;
}

void removeNewline(char text[]) {
    int i = 0;

    while (text[i] != '\0') {
        if (text[i] == '\n') {
            text[i] = '\0';
            break;
        }

        i++;
    }
}

int main() {
    char text[TEXT_SIZE];

    printf("Dzialania na slowach\n");
    printf("Wpisz pusty tekst, aby zakonczyc program.\n\n");

    while (1) {
        printf("Podaj tekst: ");
        fgets(text, TEXT_SIZE, stdin);

        removeNewline(text);

        if (text[0] == '\0') {
            break;
        }

        printf("Tekst oryginalny: %s\n", text);

        toLower(text);
        printf("Male litery: %s\n", text);

        toUpper(text);
        printf("Duze litery: %s\n", text);

        printf("Dlugosc tekstu: %d\n", textSize(text));
        printf("------------------------------\n");
    }

    return 0;
}
