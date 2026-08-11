#include <stdio.h>
#include <string.h>

int isNumeric(char type[])
{
    if (strcmp(type, "int") == 0 ||
        strcmp(type, "float") == 0)
    {
        return 1;
    }

    return 0;
}

void checkOperation(char type1[], char op, char type2[])
{
    printf("\nChecking: %s %c %s\n",
           type1, op, type2);

    /*
       Arithmetic operators are allowed
       only for numeric types.
    */

    if (isNumeric(type1) && isNumeric(type2))
    {
        if (op == '+' || op == '-' ||
            op == '*' || op == '/')
        {
            printf("Result: Valid expression\n");
        }
        else
        {
            printf("Result: Invalid operator\n");
        }
    }
    else
    {
        printf("Result: Type error\n");
    }
}

int main()
{
    char type1[20], type2[20];
    char op;

    printf("Enter first operand type (int/float/char/int*/float*/char*): ");
    scanf("%s", type1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter second operand type (int/float/char/int*/float*/char*): ");
    scanf("%s", type2);

    checkOperation(type1, op, type2);

    return 0;

