#include <stdio.h>
#include <time.h>

int Factorial(int n) {
    int fac = 1;

    for (int i = 1; i <= n; i++){
        fac *= i;
    }

    return fac;
}

void main() {
    int n;

    printf("Enter Number: ");
    scanf("%d", &n);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int ans = Factorial(n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Factorial of %d = %d\n", n, ans);
    printf("Execution Time = %f Seconds\n", cpu_time_used);

}