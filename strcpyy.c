#include <stdio.h>
#include <string.h>

int main() {
    const char source[5] = "test";
    char destination[5];
    strcpy(destination, source);
    printf("%s", destination);
    return 0;
}