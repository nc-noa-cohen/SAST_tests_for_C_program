#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    const char *source = "This string is way too long for the buffer";
    
    // FIXED: Replaced strcpy() with strncpy() to prevent buffer overflow
    strncpy(buffer, source, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';  // Ensure null termination
    
    printf("%s\n", buffer);
    printf("Note: String was truncated to fit buffer size\n");
    return 0;
}
