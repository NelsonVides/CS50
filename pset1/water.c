#include <stdio.h>
#include <cs50.h>

int main(void)
{

float minutes=0;
float bottles=0;

    //do{
        printf("For how long have you been in the shower (in minutes)? ");
        minutes = get_float();
    //}while (minutes < 0);

bottles = minutes*12;
    printf("Those are %.2f bottles, you prick!\n",bottles);

}