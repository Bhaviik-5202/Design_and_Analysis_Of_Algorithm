#include <stdio.h>
#include <time.h>
int main() {

    clock_t start, end;
    double cpu_time_used;

    int arr[] = {1, 2, 3, -4, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int pos[n], neg[n];
    int p = 0, q = 0;

    start = clock();
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            pos[p++] = arr[i];
        } else {
            neg[q++] = arr[i];
        }
    }

    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }
    if (i < p)
    {
        arr[k++] = pos[i];
    }
    if (j < q) {
        arr[k++] = neg[j];
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Pos. & Negg. Array : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nExecution Time = %f Seconds\n", cpu_time_used);
    return 0;
}