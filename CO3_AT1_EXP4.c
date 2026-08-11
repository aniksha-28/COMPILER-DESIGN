#include <stdio.h>
#include <string.h>

int typeEquivalent(char type1[], char type2[])
{
    char base1[20], base2[20];
    int pointer1 = 0, pointer2 = 0;

    strcpy(base1, type1);
    strcpy(base2, type2);

    /* Check pointer for type 1 */
    if (base1[strlen(base1) - 1] == '*')
    {
        pointer1 = 1;
        base1[strlen(base1) - 1] = '\0';
    }

    /* Check pointer for type 2 */
    if (base2[strlen(base2) - 1] == '*')
    {
        pointer2 = 1;
        base2[strlen(base2) - 1] = '\0';
    }

    /* Pointer level must be same */
    if (pointer1 != pointer2)
        return 0;

    /* Base type must be same */
    if (strcmp(base1, base2) == 0)
        return 1;

    return 0;
}

int main()
{
    char type1[20], type2[20];

    printf("Enter first type (int/float/char/int*/float*/char*): ");
    scanf("%s", type1);

    printf("Enter second type (int/float/char/int*/float*/char*): ");
    scanf("%s", type2);

    if (typeEquivalent(type1, type2))
        printf("\nResult: Equivalent\n");
    else
        printf("\nResult: Not Equivalent\n");

    return 0;
}
