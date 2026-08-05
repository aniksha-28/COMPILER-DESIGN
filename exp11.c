#include <stdio.h>
#include <string.h>

struct Symbol
{
    char name[20];
    char type[20];
    int size;
    int address;
};

struct Symbol table[100];
int count = 0;

void insertSymbol()
{
    printf("Enter Symbol Name: ");
    scanf("%s", table[count].name);

    printf("Enter Data Type: ");
    scanf("%s", table[count].type);

    printf("Enter Size: ");
    scanf("%d", &table[count].size);

    printf("Enter Memory Address: ");
    scanf("%d", &table[count].address);

    count++;
    printf("Symbol Inserted Successfully.\n");
}

void displayTable()
{
    int i;

    if(count == 0)
    {
        printf("Symbol Table is Empty.\n");
        return;
    }

    printf("\n-----------------------------------------------------\n");
    printf("Name\t\tType\tSize\tAddress\n");
    printf("-----------------------------------------------------\n");

    for(i = 0; i < count; i++)
    {
        printf("%s\t\t%s\t%d\t%d\n",
        table[i].name,
        table[i].type,
        table[i].size,
        table[i].address);
    }
}

void searchSymbol()
{
    char key[20];
    int i, found = 0;

    printf("Enter Symbol Name to Search: ");
    scanf("%s", key);

    for(i = 0; i < count; i++)
    {
        if(strcmp(table[i].name, key) == 0)
        {
            printf("\nSymbol Found\n");
            printf("Name    : %s\n", table[i].name);
            printf("Type    : %s\n", table[i].type);
            printf("Size    : %d\n", table[i].size);
            printf("Address : %d\n", table[i].address);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Symbol Not Found.\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n===== SYMBOL TABLE MENU =====\n");
        printf("1. Insert Symbol\n");
        printf("2. Display Symbol Table\n");
        printf("3. Search Symbol\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertSymbol();
                break;

            case 2:
                displayTable();
                break;

            case 3:
                searchSymbol();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}