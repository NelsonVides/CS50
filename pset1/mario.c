#include <stdio.h>
#include <cs50.h>

int main(void)
{

int n=0;
int row=0;
int i=0;
int j=0;

    do{
        printf("Tell me how many rows you want: ");
        n = get_int();
    }while (n < 0 || n > 23);

    for (row = 0; row<n; row++) //coments
    {   for (i = 0; i<n-row-1; i++)
            {printf(" ");}
        for (j = 0; j<n-i+1; j++)
            {printf("#");}
        printf("\n");
    }
}