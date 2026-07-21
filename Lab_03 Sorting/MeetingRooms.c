#include <stdio.h>
int main() {

    int n, i, j, temp;
    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int arr[n][2];

    printf("Enter Start and End Time:\n");
    for(i = 0; i < n; i++)
        scanf("%d%d", &arr[i][0], &arr[i][1]);

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j][0] > arr[j + 1][0])
            {
                temp = arr[j][0];
                arr[j][0] = arr[j + 1][0];
                arr[j + 1][0] = temp;

                temp = arr[j][1];
                arr[j][1] = arr[j + 1][1];
                arr[j + 1][1] = temp;
            }
        }
    }

    for(i = 0; i < n - 1; i++)
    {
        if(arr[i][1] > arr[i + 1][0])
        {
            printf("False");
            return 0;
        }
    }

    printf("True");

    return 0;
}