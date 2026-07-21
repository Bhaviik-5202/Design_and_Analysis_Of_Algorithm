#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i, temp;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    
    int n, k, i, j;
    int index = 0;

    printf("Enter size of arrays: ");
    scanf("%d", &n);

    int a[n], b[n];

    printf("Enter elements of array A:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter elements of array B:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    int sum[n * n];

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            sum[index++] = a[i] + b[j];
        }
    }

    heapSort(sum, index);

    printf("Top %d Maximum Sums:\n", k);

    for(i = index - 1; i >= index - k; i--)
        printf("%d ", sum[i]);

    return 0;
}