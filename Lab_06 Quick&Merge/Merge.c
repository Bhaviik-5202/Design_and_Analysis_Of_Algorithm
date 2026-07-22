#include <stdio.h>
#include <time.h>
#define SIZE 100000

void merge(int arr[], int lb, int ub, int mid) {

    int ans[SIZE];
    int i = lb;
    int j = mid+1;
    int k = lb;

    while(i <= mid && j <= ub) {
        if (arr[i] < arr[j]) {
            ans[k] = arr[i];
            i++;
        } else {
            ans[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        ans[k] = arr[i];
        i++;
        k++;
    }
    while (j <= ub) {
        ans[k] = arr[j];
        j++;
        k++;
    }
    
    for (int i = lb; i <= ub; i++){
        arr[i] = ans[i];
    }

}

void mergeSort(int arr[], int lb, int ub) {
    if (lb >= ub) {
        return;
    }
    
    int mid = lb + (ub - lb) / 2;
    mergeSort(arr, lb, mid);
    mergeSort(arr, mid+1, ub);
    merge(arr, lb, ub, mid);

}

int main() {

    int arr[SIZE];

    // FILE *file = fopen("Avg_1000.txt", "r");
    // FILE *file = fopen("Avg_10000.txt", "r");
    FILE *file = fopen("Avg_100000.txt", "r");

    if (file == NULL)
    {
        printf("Error Opening Worst_1000.txt\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (fscanf(file, "%d", &arr[i]) != 1)
        {
            printf("Error Reading File\n");
            fclose(file);
            return 1;
        }
    }
    fclose(file);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    mergeSort(arr, 1, (SIZE-1));
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    for(int i = 0; i < SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}