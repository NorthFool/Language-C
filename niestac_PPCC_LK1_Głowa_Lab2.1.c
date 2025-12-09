#include <stdio.h>
int main()
{
    long long x = 0, y = 1;   // pierwsze dwa wyrazy ciągu Fibonacciego
    int z;                    // zmienna przechowująca liczbę iteracji (ile wyrazów wypisać)

    printf("Podaj ile chcesz wypisac wyrazow ciagu Fibonacciego: ");
    scanf("%d", &z);          // pobieramy od użytkownika liczbę wyrazów

    for(int i = 0; i < z; i++)    // pętla wykonująca się z razy
    {
        printf("%lld ", y);      // wypisujemy aktualny wyraz ciągu
        y = y + x;               // obliczamy kolejny wyraz
        x = y - x;               // przesuwamy wartości: nowe x to poprzednie y
    }
    getchar();
    return 0;
}
