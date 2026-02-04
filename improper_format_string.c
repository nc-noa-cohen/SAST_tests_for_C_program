#include <stdio.h>

int main() {
    char buf[100];
    scanf("%99s", buf);  // Limit input to prevent buffer overflow
    
    // FIXED: Use proper format specifier to prevent format string vulnerability
    printf("%s", buf);  // Safe: format string is controlled, not user input
    
    return 0;
}
