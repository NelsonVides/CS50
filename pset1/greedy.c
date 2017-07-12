#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

float dollars=0;
int cents=0;
int coins=0;

    do{
        printf("How much do I owe you? ");
        dollars = get_float();
    }while (dollars < 0);
    cents=roundf(dollars*100);
    //printf("%i\n", cents);

while (cents - 25>=0)
{    cents=cents - 25;
     coins=coins+1;
}

while (cents - 10>=0)
{    cents=cents - 10;
     coins=coins+1;
}

while (cents - 5>=0)
{    cents=cents - 5;
     coins=coins+1;
}

if (cents >0)
{
    coins=coins+cents;
}

    printf("%i\n",coins);
}