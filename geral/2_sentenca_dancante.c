#include <stdio.h>
#include <ctype.h>

int main() {
    char frase[51];
    int i, ehOPrimeiro = 1;

    while(fgets(frase, 51, stdin) != NULL) {
        for(i = 0; frase[i] != '\0'; i++) {
            if(isalpha(frase[i])) {
                if(ehOPrimeiro || !isupper(frase[i-1])) {
                    frase[i] = toupper(frase[i]);
                } else {
                    frase[i] = tolower(frase[i]);
                }

                ehOPrimeiro = 0;
            }

            printf("%c", frase[i]);
        }

        ehOPrimeiro = 1;
    }

    return 0;
}