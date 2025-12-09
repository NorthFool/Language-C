#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//sortownaie bombelkowe
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            int *a = arr + j;  
            int *b = arr + j + 1;

            if (*a > *b) {
                int temp = *a;
                *a = *b;
                *b = temp;
            }
        }
    }
}
//sortowanie merge
void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++)
        *(L + i) = *(arr + left + i);

    for (int i = 0; i < n2; i++)
        *(R + i) = *(arr + mid + 1 + i);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (*(L + i) <= *(R + j))
            *(arr + k++) = *(L + i++);
        else
            *(arr + k++) = *(R + j++);
    }

    while (i < n1)
        *(arr + k++) = *(L + i++);
    while (j < n2)
        *(arr + k++) = *(R + j++);

    free(L);
    free(R);
}
//sortowanie merge 2
void mergeSort(int *arr, int left, int right) {
    if (left < right) {

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    printf("Podaj rozmiar tablicy: ");
    scanf("%d", &n);

    int *tablica = malloc(n * sizeof(int));
    int *kopia = malloc(n * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        *(tablica + i) = rand() % 1000 + 1;
        *(kopia + i) = *(tablica + i);
    }

    clock_t start1 = clock();
    bubbleSort(tablica, n);
    clock_t end1 = clock();

    clock_t start2 = clock();
    mergeSort(kopia, 0, n - 1);
    clock_t end2 = clock();

    printf("\nCzas Bubble Sort (pointer):  %f s\n",
           (double)(end1 - start1) / CLOCKS_PER_SEC);
    printf("Czas Merge Sort  (pointer):  %f s\n",
           (double)(end2 - start2) / CLOCKS_PER_SEC);

    free(tablica);
    free(kopia);

    return 0;
}
