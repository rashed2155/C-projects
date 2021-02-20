#include <stdio.h>
int main()
{
    char str[100];
    printf("Enter a String : ");
    gets(str);
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    printf("String Length is = %d", length);
    return 0;
}
