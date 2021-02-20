#include <stdio.h>
int main()
{
    char string1[200];
    printf("Enter 1st String : ");
    gets(string1);
    char string2[200];
    printf("Enter 2nd String : ");
    gets(string2);
    int i = 0, j = 0, length = 0;
    for (i = 0; string1[i] != '\0'; i++)
    {
        for (j = 0; string2[j] != '\0'; j++)
        {
            if (string1[i] == string2[j])
            {
                length++;
            }
            else
            {
                length = 0;
            }
        }
    }
    if (length > 0)
    {
        printf("Two strings are same\n");
    }
    else
    {
        printf("Two strings are NOT Same.\n");
    }
}