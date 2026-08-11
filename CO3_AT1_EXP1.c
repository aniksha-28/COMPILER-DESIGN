#include <stdio.h>
#include <ctype.h>

char expr[100];
int pos = 0;

/* Function declarations */
int E();
int T();
int F();

/* Skip spaces */
void skipSpaces()
{
    while (expr[pos] == ' ')
        pos++;
}

/* E -> T { (+|-) T } */
int E()
{
    int val = T();

    while (1)
    {
        skipSpaces();

        if (expr[pos] == '+')
        {
            pos++;
            val = val + T();
        }
        else if (expr[pos] == '-')
        {
            pos++;
            val = val - T();
        }
        else
        {
            break;
        }
    }

    return val;
}

/* T -> F { (*|/) F } */
int T()
{
    int val = F();

    while (1)
    {
        skipSpaces();

        if (expr[pos] == '*')
        {
            pos++;
            val = val * F();
        }
        else if (expr[pos] == '/')
        {
            pos++;
            val = val / F();
        }
        else
        {
            break;
        }
    }

    return val;
}

/* F -> (E) | digit */
int F()
{
    int val = 0;

    skipSpaces();

    if (expr[pos] == '(')
    {
        pos++;
        val = E();

        skipSpaces();

        if (expr[pos] == ')')
            pos++;
    }
    else if (isdigit(expr[pos]))
    {
        while (isdigit(expr[pos]))
        {
            val = val * 10 + (expr[pos] - '0');
            pos++;
        }
    }

    return val;
}

int main()
{
    printf("Enter arithmetic expression: ");
    scanf("%s", expr);

    printf("Result = %d\n", E());

    return 0;
}
