#include <stdio.h>
#include <time.h>
/*
Time Complexity: O(√n)
Space Complexity: O(1)
*/
// void primeFactors(int n) {
//     while (n % 2 == 0)
//     {
//         printf("%d ", 2);
//         n /= 2;
//     }

//     for (int i = 3; i * i <= n; i += 2)
//     {
//         while (n % i == 0)
//         {
//             printf("%d ", i);
//             n /= i;
//         }
//     }

//     if (n > 2)
//     {
//         printf("%d", n);
//     }
// }

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
void primeFactors(int n) {
    int c = 2;

    while (n > 1) {
        if (n % c == 0) {
            printf("%d ", c);
            n /= c;
        }
        else {
            c++;
        }
    }
}

void main() {
    int n;

    printf("Enter Number: ");
    scanf("%d", &n);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    printf("Prime Factors: ");
    primeFactors(n);
    printf("\n");
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time = %f Seconds\n", cpu_time_used);


}