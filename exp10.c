#include <stdio.h>
#include <string.h>

int main()
{
    char p1[50], p2[50], common[50];
    int i = 0;

    printf("Enter Production 1: ");
    scanf("%s", p1);

    printf("Enter Production 2: ");
    scanf("%s", p2);

    while(p1[i] == p2[i] && p1[i] != '\0')
    {
        common[i] = p1[i];
        i++;
    }

    common[i] = '\0';

    printf("\nGrammar after Left Factoring:\n");
    printf("S  -> %sS'\n", common);
    printf("S' -> %s | %s\n", p1 + i, p2 + i);

    return 0;
}