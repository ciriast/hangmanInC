#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Start game!\n");
    
    char characterFromUser[2];
    
    printf("Note: You can enter only one letter, if you enter more than one, only the first character will be take it.\n");
    printf("Enter a letter:");

    fgets(characterFromUser, sizeof(characterFromUser), stdin);
    
    char characterToUse = tolower(characterFromUser[0]);
    printf("You entered: %c\n", characterToUse);

    if ((characterToUse < 'a' || characterToUse > 'z') || (characterToUse > 'a' && characterToUse > 'z')) {
        printf("The character is not an alphabet.");
        return 0;
    }

    return 0;
}
