#include <stdio.h>

int main() {
    char buffer[50];

    printf("Enter a string: ");
    // FIXED: Replaced gets() with fgets() for safe buffer handling
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Remove trailing newline if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
        printf("You entered: %s\n", buffer);
    }
    return 0;
}
