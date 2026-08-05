#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char str[])
{
    char keywords[][20] = {
        "int", "float", "char", "if", "else", "while",
        "for", "return", "void", "break", "continue",
        "double", "long", "short", "switch", "case",
        "default", "do", "struct", "typedef"
    };

    int n = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch)
{
    char operators[] = "+-*/%=<>!&|^";
    for (int i = 0; operators[i] != '\0'; i++)
    {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int main()
{
    FILE *fp;
    char ch, token[100];
    int i;

    fp = fopen("input.c", "r");

    if (fp == NULL)
    {
        printf("Cannot open input.c\n");
        return 0;
    }

    printf("Identifiers:\n");
    printf("-----------------\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        /* Ignore single-line comments */
        if (ch == '/')
        {
            char next = fgetc(fp);

            if (next == '/')
            {
                while ((ch = fgetc(fp)) != '\n' && ch != EOF);
                continue;
            }
            else if (next == '*')
            {
                while ((ch = fgetc(fp)) != EOF)
                {
                    if (ch == '*')
                    {
                        if ((ch = fgetc(fp)) == '/')
                            break;
                    }
                }
                continue;
            }
            else
            {
                fseek(fp, -1, SEEK_CUR);
            }
        }

        /* Ignore spaces, tabs, newlines */
        if (isspace(ch))
            continue;

        /* Identifier or Keyword */
        if (isalpha(ch) || ch == '_')
        {
            i = 0;
            token[i++] = ch;

            while ((ch = fgetc(fp)) != EOF &&
                  (isalnum(ch) || ch == '_'))
            {
                token[i++] = ch;
            }

            token[i] = '\0';

            if (!isKeyword(token))
                printf("%s\n", token);

            if (ch != EOF)
                fseek(fp, -1, SEEK_CUR);
        }

        /* Constant */
        else if (isdigit(ch))
        {
            i = 0;
            token[i++] = ch;

            while ((ch = fgetc(fp)) != EOF &&
                  (isdigit(ch) || ch == '.'))
            {
                token[i++] = ch;
            }

            token[i] = '\0';

            printf("Constant : %s\n", token);

            if (ch != EOF)
                fseek(fp, -1, SEEK_CUR);
        }

        /* Operator */
        else if (isOperator(ch))
        {
            printf("Operator : %c\n", ch);
        }
    }

    fclose(fp);

    return 0;
}