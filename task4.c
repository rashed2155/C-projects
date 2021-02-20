#include <stdio.h>
int main()
{
    char str1[100];
    char str2[100];
    int length = 0;
    int i = 0, j = 0;
    printf("Enter a String : ");
    gets(str1);
    for (i = 0; str1[i] != '\0'; i++)
    {
        length++;
    }
    for (i = length - 1; i >= 0; i--)
    {
        str2[j] = str1[i];
        j++;
    }
    puts(str2);
}