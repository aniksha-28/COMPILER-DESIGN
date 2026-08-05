#include <stdio.h>

char followS[10], followA[10], followB[10];
int fs = 0, fa = 0, fb = 0;

void addToFollow(char follow[], int *size, char symbol)
{
    int i;
    for(i = 0; i < *size; i++)
    {
        if(follow[i] == symbol)
            return;
    }
    follow[(*size)++] = symbol;
}

void FOLLOW_S()
{
    // Start symbol
    addToFollow(followS, &fs, '$');
}

void FOLLOW_A()
{
    // S -> A a A b
    addToFollow(followA, &fa, 'a');   // First A is followed by 'a'
    addToFollow(followA, &fa, 'b');   // Second A is followed by 'b'
}

void FOLLOW_B()
{
    // S -> B b B a
    addToFollow(followB, &fb, 'b');   // First B is followed by 'b'
    addToFollow(followB, &fb, 'a');   // Second B is followed by 'a'
}

int main()
{
    int i;

    FOLLOW_S();
    FOLLOW_A();
    FOLLOW_B();

    printf("FOLLOW(S) = { ");
    for(i = 0; i < fs; i++)
        printf("%c ", followS[i]);
    printf("}\n");

    printf("FOLLOW(A) = { ");
    for(i = 0; i < fa; i++)
        printf("%c ", followA[i]);
    printf("}\n");

    printf("FOLLOW(B) = { ");
    for(i = 0; i < fb; i++)
        printf("%c ", followB[i]);
    printf("}\n");

    return 0;
}