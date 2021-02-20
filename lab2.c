#include <stdio.h> #include<string.h> 
int main()
{
    char str1[1000] = "Today is very cold in daffodil international university(Ashulia),khagan(savar),etc";
    char *word;
    word = strtok(str1, " ,()");
    printf("%s\n", word);
    while (word != '\0')
    {
        word = strtok('\0', " ,:()");
        printf("%s\n", word);
    }
    return 0;
}