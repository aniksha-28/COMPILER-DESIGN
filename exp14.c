#include <stdio.h>
#include <string.h>

int main()
{
    char expr[50];
    char op1, op2, opr;
    int temp = 1;

    printf("Enter expression (Example: a+b): ");
    scanf("%s", expr);

    op1 = expr[0];
    opr = expr[1];
    op2 = expr[2];

    printf("\nThree Address Code:\n");

    printf("t%d = %c %c %c\n", temp, op1, opr, op2);

    return 0;
}