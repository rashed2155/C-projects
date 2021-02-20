#include <stdio.h> 
int main()
{
    char string1[200];
    char string2[200];
    int length = 0;
    int i = 0, j = 0, n;
    printf("Enter a String : ");
    gets(string1);
    for (i = 0; string1[i] != '\0'; i++)
    {
        length++;
    }
    for (i = length - 1; i >= 0; i--)
    {
        string2[length - i - 1] = string1[i];
    }
    for (n = 1, i = 0; i < length; i++)
    {
        if (string2[i] != string1[i])
        {
            n = 0;
        }
    }
    if (n == 1)
        printf("%s is palindrome.", string1);
    else
        printf("%s is not a palindrome", string1);
    return 0;
}