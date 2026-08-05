#include <stdio.h>
#include <string.h>

int main()
{
    char lhs[10], alpha[20], beta[20];

    strcpy(lhs, "L");
    strcpy(alpha, ",S");   // Recursive part
    strcpy(beta, "S");     // Non-recursive part

    printf("Original Grammar:\n");
    printf("S -> (L) | a\n");
    printf("L -> L,S | S\n");

    printf("\nGrammar after Eliminating Left Recursion:\n");
    printf("%s -> %s %s'\n", lhs, beta, lhs);
    printf("%s' -> %s %s' | e\n", lhs, alpha, lhs);

    return 0;
}