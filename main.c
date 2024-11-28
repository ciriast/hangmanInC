#include <stdio.h>

int main() {
    printf("Start game!\n");
    
    char characterFromUser[50];

    printf("Enter a letter:");

    fgets(characterFromUser, sizeof(characterFromUser), stdin);
    printf("%ld", sizeof(characterFromUser));
    printf("You entered: %s", characterFromUser);

    return 0;
}
