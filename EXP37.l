%{
#include <stdio.h>
#include <string.h>

char target[50];
int count = 0;
%}

%%

[A-Za-z]+ {
    if (strcmp(yytext, target) == 0)
        count++;
}

\n {
    printf("\nFrequency of \"%s\" = %d\n", target, count);
    return 0;
}

. ;

%%

int main()
{
    printf("Enter the word to search: ");
    scanf("%s", target);

    printf("Enter the sentence: ");
    getchar();

    yylex();

    return 0;
}

int yywrap()
{
    return 1;
}