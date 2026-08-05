#include <stdio.h>
#include <string.h>

int main()
{
    char exp[100];
    int i;

    printf("Enter an expression: ");
    fgets(exp, sizeof(exp), stdin);

    printf("\nArithmetic Operators Found:\n");

    for(i = 0; exp[i] != '\0'; i++)
    {
        switch(exp[i])
        {
            case '+':
                printf("+ : Addition Operator\n");
                break;

            case '-':
                printf("- : Subtraction Operator\n");
                break;

            case '*':
                printf("* : Multiplication Operator\n");
                break;

            case '/':
                printf("/ : Division Operator\n");
                break;
        }
    }

    return 0;
}