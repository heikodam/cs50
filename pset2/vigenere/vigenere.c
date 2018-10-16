#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //check if a argument was entered in the CLI
    if(argc == 2)
    {
        string keyword = argv[1];
        //check if key only has letters
        for(int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if(!(isalpha(keyword[i])))
            {
                printf("Please only Enter letters for the keyword\n");
                return 1;
            }
        }

        // k is the key value, how many positions should you move
        int k;
        //get text to cypher
        string p = get_string("plaintext: ");
        printf("ciphertext: ");

        //cyper and print cypheredtext
        for(int i = 0, n = strlen(p); i < n; i++)
        {
            if(isalpha(p[i]))
            {
                if(isupper(keyword[i % strlen(keyword)]))
                {
                     k = keyword[i % strlen(keyword)] - 65;
                } else if (islower(keyword[i % strlen(keyword)]))
                {
                    k = keyword[i % strlen(keyword)] - 97;
                }
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
        return 1;
    }
}