#include <stdio.h> 
int main()
{
    int i, j, length = 0;
    char str1[100], str2[100];
    printf("Enter 1st String : ");
    gets(str1);
    printf("Enter 2nd String : ");
    gets(str2);
    for (i = 0; str1[i] != '\0'; i++)
    {
        length++;
    }
    str1[length] = ' ';
    length++;
    for (j = 0; str2[j] != '\0'; j++, length++)
    {
        str1[length] = str2[j];
    }
    str1[length] = '\0';
    puts(str1);
}