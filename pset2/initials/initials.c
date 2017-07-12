#include <stdio.h>
#include <cs50.h>
//#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{   //ask for his name
    //printf("Hey man, how is your name?\n");
    string name = get_string();

    if (name != NULL)
    {
        int aux=0; //aux=0 indicará puedo imprimir esta
        for (int i = 0, n = strlen(name); i < n; i++)
        {
            if (name[i] != ' ' && aux==0)
            {
                printf("%c", toupper(name[i]));
                aux=1;
            }
            else if (name[i]==' ')
            {aux=0;}
        }
    }

printf("\n");
}