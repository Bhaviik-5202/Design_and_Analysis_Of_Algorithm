#include <stdio.h>
int main() {

    int n, i, j, temp, minDiff;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    minDiff = arr[1] - arr[0];

    for(i = 1; i < n - 1; i++)
    {
        if(arr[i + 1] - arr[i] < minDiff)
            minDiff = arr[i + 1] - arr[i];
    }

    printf("Minimum Difference = %d", minDiff);

    return 0;
}