#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

/* Push value */
void push(int value)
{
    stack[++top] = value;
}

/* Pop value */
int pop()
{
    return stack[top--];
}

/* Evaluate postfix expression */
int evaluatePostfix(char exp[])
{
    int i;
    int a, b, result;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');

            printf("Push %d\n", exp[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch (exp[i])
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                default:
                    result = 0;
            }

            printf("%d %c %d = %d\n",
                   a, exp[i], b, result);

            push(result);
        }
    }

    return pop();
}

int main()
{
    char exp[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    printf("\nIntermediate computations:\n");

    printf("\nFinal Result = %d\n",
           evaluatePostfix(exp));

    return 0;
}
