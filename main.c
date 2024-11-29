#include <stdio.h>

int main() {
    printf("Start game!\n");
    
    char characterFromUser[2];
    
    printf("Note: You can enter only one letter, if you enter more than one, only the first character will be take it.\n");
    printf("Enter a letter:");

    fgets(characterFromUser, sizeof(characterFromUser), stdin);
    printf("You entered: %s\n", characterFromUser);

    return 0;
}
