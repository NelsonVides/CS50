#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) //sanity check for umproper prompt line
        {printf("Usage: ./crack hash\n");return 1;}

    if (strlen(argv[1])!=13) //sanity check for improper hash
        {printf("Not a DES hash\n");return 1;}

    char salt[3]; // create salt
        memset(salt, '\0', 3);
            strncpy(salt, argv[1], 2);
    char hash[14]; // create hash
        memset(hash, '\0', 14);
            strncpy(hash, argv[1],13);

    char key[5]; //create key
        memset(key, '\0', sizeof(key));
    char hashtest[14]; //create hash to test
        memset(hashtest, '\0', 14);

    //the characters to bucle through in the loop
    string alphabet={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuwxyz"};

for (int i = 0; i <=52; i++)            //make the key to test
{   key[0]=alphabet[i];                 //make the key to test
    for (int j = 0; j <=52; j++)        //make the key to test
    {   key[1]=alphabet[j];             //make the key to test
        for (int k = 0; k <=52; k++)    //make the key to test
        {   key[2]=alphabet[k];         //make the key to test
            for (int l = 0; l <=52; l++)//make the key to test
            {   key[3]=alphabet[l];     //make the key to test
                
                // create hashtest to try it out
                strncpy(hashtest, crypt (key,salt),13);
                
                // tadarataaaan
                if (strcmp(hash,hashtest)==0)
                    {printf("%s\n", key);return 0;}
            }
        }
    }
}
}

//andi:50.jPgLzVirkc
//jason:50YHuxoCN9Jkc
//malan:50QvlJWn2qJGE
//mzlatkova:50CPlMDLT06yY
//patrick:50WUNAFdX/yjA
//rbowden:50fkUxYHbnXGw
//summer:50C6B0oz0HWzo
//stelios:50nq4RV/NVU0I
//wmartin:50vtwu4ujL.Dk
//zamyla:50i2t3sOSAZtk