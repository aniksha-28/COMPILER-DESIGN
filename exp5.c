#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, spaces = 0;

    printf("Enter a line: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ')
            spaces++;
    }

    // Since fgets() reads one line, it contains one newline character.
    printf("\nNumber of White Spaces = %d\n", spaces);
    printf("Number of New Lines = 1\n");

    return 0;
}