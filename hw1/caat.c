#include <stdio.h>

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            putchar(c);
        }
    }

    return 0;
}
