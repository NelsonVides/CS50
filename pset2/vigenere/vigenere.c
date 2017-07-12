#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{   
//sanity check for improper prompt line
    if (argc != 2)
        {printf("Usage: ./vigeneres key\n");return 1;}

// make the key
    char *key = argv[1];
        if (key == NULL){return 1;}
    int len = strlen(argv[1]);
    
//check if totally alphanumeric, and if so, to lower, in one iteration
    int k=0;
    while (k < len)
    {
        if (!isalpha(key[k])){printf("ERROR: non-alphabetic values\n");return 1;}
        key[k]=tolower(key[k]);
        k++;
    }
    
// ask for the plaintext
    printf("plaintext: ");
        char *name = get_string();
            int n = strlen(name);

int temp; int j = 0;
for (int i = 0; i < n; i++)
{   
    if (isalpha(name[i]))
    {   
        if (name[i]<=90)
        {   
            temp = (name[i]+key[j]-97);
            if (temp<91)
            {name[i] = (char) temp;}
            else
            {name[i] = (char) (temp%91 + 65);}
            j = (j+1) % len;
        }
        else
        {
            temp = (name[i]+key[j]-97);
            if (temp<123)
            {name[i] = (char) temp;}
            else
            {name[i] = (char) (temp%123 + 97);}
            j = (j+1) % len;
        }
    }
}
printf("ciphertext: %s\n", name);
}