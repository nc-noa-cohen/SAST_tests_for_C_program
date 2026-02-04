/*
    This program demonstrates secure password handling using environment variables
    instead of hardcoded credentials.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char inputPassword[50];
    
    // FIXED: Use environment variable instead of hardcoded password
    const char *systemPassword = getenv("SYSTEM_PASSWORD");
    
    if (systemPassword == NULL) {
        fprintf(stderr, "Error: SYSTEM_PASSWORD environment variable not set\n");
        fprintf(stderr, "Please set it using: export SYSTEM_PASSWORD=your_password\n");
        return 1;
    }

    printf("Enter password to access the system file: ");
    fgets(inputPassword, sizeof(inputPassword), stdin);
    inputPassword[strcspn(inputPassword, "\n")] = 0; // Remove newline character

    if (strcmp(inputPassword, systemPassword) == 0) {
        printf("Access granted. Reading system file...\n");

        // Attempting to read a system-critical file (with a fake filename)
        const char *criticalFilePath = "/etc/fake_critical_file.conf";
        FILE *file = fopen(criticalFilePath, "r");

        if (file == NULL) {
            perror("Error opening file");
        } else {
            // Read and print the contents of the file (hypothetical)
            char buffer[256];
            while (fgets(buffer, sizeof(buffer), file) != NULL) {
                printf("%s", buffer);
            }
            fclose(file);
        }
    } else {
        printf("Access denied.\n");
    }

    return 0;
}
