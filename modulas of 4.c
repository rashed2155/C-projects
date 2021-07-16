#include <stdio.h>

void seat(int arr[], int N);

int main()
{
    int N, i;
    scanf("%d", &N);
    int arr[N];
    for (i = 0; i < N; i++)
    {
        printf("Enter %d no. Digit : ", i);
        scanf("%d", &arr[i]);
    }
    seat(arr, N);
}
void seat(int arr[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (arr[i] % 4 == 0)
        {
            printf("%d ", arr[i]);
        }
    }
}