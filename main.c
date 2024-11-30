#include <stdio.h> 
#include <ctype.h>
#include <string.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Ok, this buffer thing is a little confusing, seems the stdin saves thing that I don't want to the rest of the while loop, so I need to manually clean it.
// I don't know why this little details aren't mentioned in the docs.
// I needed help to understand the buffer thing, it's confusing
int main() {
    printf("Start game!\n");
    char wordToGuess[5] = "hello";    
    int remaining_lives = 3;

    printf("Note: You can enter only one letter, if you enter more than one, only the first character will be take it.\n");

    while (remaining_lives > 0) {
        char my_input[10];
        char characterFromUser;

        printf("You have %d remaining lives\n", remaining_lives);
        printf("Enter a letter:");

        fgets(my_input, sizeof(my_input), stdin);

        characterFromUser = tolower(my_input[0]);
        printf("You entered: %c\n", characterFromUser);

        if (characterFromUser < 'a' || characterFromUser > 'z') {
            printf("The character is not an alphabet.\n");
        }
        
        clear_input_buffer();
        --remaining_lives;
    }

    return 0;
}
