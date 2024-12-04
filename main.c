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
    char wordToGuess[6] = "hello";
    char showing_word[6] = "_____";
    int remaining_lives = 3;
    int number_of_word_guessed = 5;

    printf("Note: You can enter only one letter, if you enter more than one, only the first character will be take it.\n");
    printf("The word contains five letters: %s\n", showing_word);

    while (remaining_lives > 0 && number_of_word_guessed > 0) {
        int lost_life = 1;
        char my_input[10];
        size_t len = 0;
        char characterFromUser;
        int is_alphabet = 1;

        printf("You have %d remaining lives\n", remaining_lives);
        printf("Enter a letter:");
        
        fgets(my_input, sizeof(my_input), stdin);

        characterFromUser = tolower(my_input[0]);
        printf("You entered: %c\n", characterFromUser);

        if (characterFromUser < 'a' || characterFromUser > 'z') {
            printf("The character is not an alphabet.\n");
            is_alphabet = 0;
        }
        
        len = strlen(my_input);

        if (len && my_input[len - 1] == '\n')
            my_input[--len] = 0;
        else
            clear_input_buffer();
        
        for (int i = 0; i < sizeof(wordToGuess) / sizeof(wordToGuess[0]) && is_alphabet == 1; ++i) {
            if (wordToGuess[i] == characterFromUser && showing_word[i] != characterFromUser) { 
                lost_life = 0;
                showing_word[i] = characterFromUser;
                --number_of_word_guessed;
            }
        }
        
        printf("Word to guess: %s\n", showing_word);

        if (lost_life == 1 && is_alphabet == 1)
            --remaining_lives;
    }
    
    if (remaining_lives > 0)
        printf("You win!\n");
    else
        printf("You lost.\n");

    return 0;
}
