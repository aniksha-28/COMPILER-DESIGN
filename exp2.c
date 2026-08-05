#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];

    printf("Enter a line:\n");
    fgets(str, sizeof(str), stdin);

    // Check for single-line comment
    if (strncmp(str, "//", 2) == 0)
    {
        printf("Single-line Comment\n");
    }
    // Check for multi-line comment
    else if (strncmp(str, "/*", 2) == 0)
    {
        if (strstr(str, "*/") != NULL)
        {
            printf("Multi-line Comment\n");
        }
        else
        {
            printf("Incomplete Multi-line Comment\n");
        }
    }
    else
    {
        printf("Not a Comment\n");
    }

    return 0;
}