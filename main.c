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
// After many failures this solution seems to work fine
// Thanks to this stackoverflow question
// https://stackoverflow.com/questions/51227542/how-to-avoid-pressing-enter-twice-when-using-getchar-to-clear-input-buffer
int main() {
    printf("Start game!\n");
    char wordToGuess[5] = "hello";    
    int remaining_lives = 2;

    printf("Note: You can enter only one letter, if you enter more than one, only the first character will be take it.\n");

    while (remaining_lives > 0) {
        char my_input[10];
        size_t len = 0;
        char characterFromUser;
        
        for (int i = 0; i < sizeof(my_input) / sizeof(my_input[0]); ++i) {
            if (my_input[i] != '\0') {
                my_input[i] = '\0';
            }
        }
        
        if (characterFromUser != '\0') {
            characterFromUser = '\0';
        }

        printf("%s", my_input);
        printf("You have %d remaining lives\n", remaining_lives);
        printf("Enter a letter:");
        
        fgets(my_input, sizeof(my_input), stdin);

        characterFromUser = tolower(my_input[0]);
        printf("You entered: %c\n", characterFromUser);

        if (characterFromUser < 'a' || characterFromUser > 'z') {
            printf("The character is not an alphabet.\n");
        }
        
        --remaining_lives;
        
        len = strlen(my_input);
        if (len && my_input[len - 1] == '\n')
            my_input[--len] = 0;
        else
            clear_input_buffer();
    }

    return 0;
}
