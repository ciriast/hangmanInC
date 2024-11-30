#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    printf("Start game!\n");
    char wordToGuess[5] = "hello";    
    int remaining_lives = 3;

    printf("Note: You can enter only one letter, if you enter more than one, only the first character will be take it.\n");

    while (remaining_lives > 0) {
        char characterFromUser;

        printf("Debugging character %c\n", characterFromUser);
        printf("You have %d remaining lives\n", remaining_lives);
        printf("Enter a letter:");

        scanf(" %c", &characterFromUser);
    
        characterFromUser = tolower(characterFromUser);
        printf("You entered: %c\n", characterFromUser);

        if (characterFromUser < 'a' || characterFromUser > 'z') {
            printf("The character is not an alphabet.\n");
        }

        --remaining_lives;
    }

    return 0;
}
