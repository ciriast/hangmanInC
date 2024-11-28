#include <stdio.h>

int main() {
    printf("Start game!\n");
    
    char characterFromUser[50];

    printf("Enter a character:");

    fgets(characterFromUser, sizeof(characterFromUser), stdin);
    printf("You entered: %s", characterFromUser);

    return 0;
}
