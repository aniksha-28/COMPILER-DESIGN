#include <stdio.h>

int main()
{
    FILE *fp;
    char ch, next;

    fp = fopen("input.c", "r");

    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    printf("Source code after removing spaces and comments:\n\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        // Ignore spaces, tabs and new lines
        if (ch == ' ' || ch == '\t' || ch == '\n')
            continue;

        // Check for comments
        if (ch == '/')
        {
            next = fgetc(fp);

            // Single-line comment
            if (next == '/')
            {
                while ((ch = fgetc(fp)) != '\n' && ch != EOF);
            }
            // Multi-line comment
            else if (next == '*')
            {
                while ((ch = fgetc(fp)) != EOF)
                {
                    if (ch == '*')
                    {
                        next = fgetc(fp);
                        if (next == '/')
                            break;
                        else
                            ungetc(next, fp);
                    }
                }
            }
            else
            {
                putchar(ch);
                ungetc(next, fp);
            }
        }
        else
        {
            putchar(ch);
        }
    }

    fclose(fp);
    return 0;
}