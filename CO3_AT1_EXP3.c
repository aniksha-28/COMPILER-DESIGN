#include <stdio.h>

/*
   L-attributed evaluation

   Function parameters act as inherited attributes.
   The current value is passed from parent to child.
*/

/* Evaluate multiplication */
int evaluateT(int inherited, int b, int c)
{
    int result;

    result = b * c;

    printf("Inherited value = %d\n", inherited);
    printf("b * c = %d * %d = %d\n", b, c, result);

    return inherited + result;
}

/* Evaluate addition */
int evaluateE(int a, int b, int c)
{
    int inherited;

    /* a is passed from parent to child */
    inherited = a;

    printf("Inherited attribute passed to T = %d\n",
           inherited);

    return evaluateT(inherited, b, c);
}

int main()
{
    int a, b, c;
    int result;

    printf("Enter values of a, b and c: ");
    scanf("%d %d %d", &a, &b, &c);

    result = evaluateE(a, b, c);

    printf("\nExpression: a + b * c\n");
    printf("Result = %d\n", result);

    return 0;
}
