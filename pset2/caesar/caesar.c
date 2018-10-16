#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc == 2)
    {
        int k = atoi(argv[1]);
        string p = get_string("plaintext: ");
        printf("ciphertext: ");

        for(int i = 0, n = strlen(p); i < n; i++)
        {
            if(isalpha(p[i]))
            {
                if(isupper(p[i]))
                {
                    int a = (int)p[i] - 65;
                    a += k;
                    a = a % 26;
                    a += 65;
                    printf("%c", a);

                } else if (islower(p[i]))
                {
                    int a = (int)p[i] - 97;
                    a += k;
                    a = a % 26;
                    a += 97;
                    printf("%c", a);
                }

            } else
            {
                printf("%c", p[i]);
            }
        }
        printf("\n");

    } else
    {
        printf("You forgot to enter a key...\n");
        printf("Arguments Entered: %i , Arguments Expected: 1 \n", argc - 1);
    }
}