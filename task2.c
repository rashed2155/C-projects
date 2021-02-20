#include <stdio.h>
#define MAX_SIZE 100 // Maximum string size

int main()
{
    char str[MAX_SIZE];
    int len, s, e;

    /* Input string from user */
    printf("Enter any string: ");
    gets(str);

    /* Find length of the string */
    len = 0;
    while (str[len] != '\0')
        len++;

    s = 0;
    e = len - 1;

    while (s <= e)
    {
        if (str[s] != str[e])
            break;

        s++;
        e--;
    }

    if (s >= e)
    {
        printf("String is Palindrome.");
    }
    else
    {
        printf("String is Not Palindrome.");
    }

    return 0;
}