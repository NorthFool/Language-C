#include <stdio.h>
#include <stdlib.h>

int main() {
    int wybor, wyborBiletu;
    float konto = 0.0;
    float wplata;

    do {
        //czyści ekran
        system("cls");
        // Menu główne
        printf("===== AUTOMAT BILETOWY =====\n");
        printf("1. Kup bilet\n");
        printf("2. Stan konta\n");
        printf("3. Doladowanie konta\n");
        printf("4. Wyjscie\n");
        printf("Wybierz opcje: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1:
                // Zakup biletu
                printf("\n--- Kup bilet ---\n");
                printf("1. Ulgowy - 3 zl\n");
                printf("2. Normalny - 6 zl\n");
                printf("3. 7-dniowy - 28 zl\n");
                printf("Wybierz bilet: ");
                scanf("%d", &wyborBiletu);
                if (wyborBiletu == 1) {
                    if (konto >= 3) {
                        konto -= 3;
                        printf("Zakupiono bilet ulgowy.\n");
                    } else {
                        printf("Brak srodkow! Masz %.2f zl, potrzebujesz 3 zl.\n", konto);
                    }
                }
                else if (wyborBiletu == 2) {
                    if (konto >= 6) {
                        konto -= 6;
                        printf("Zakupiono bilet normalny.\n");
                    } else {
                        printf("Brak srodkow! Masz %.2f zl, potrzebujesz 6 zl.\n", konto);
                    }
                }
                else if (wyborBiletu == 3) {
                    if (konto >= 28) {
                        konto -= 28;
                        printf("Zakupiono bilet 7-dniowy.\n");
                    } else {
                        printf("Brak srodkow! Masz %.2f zl, potrzebujesz 28 zl.\n", konto);
                    }
                }
                else {
                    printf("Niepoprawny wybor!\n");
                }
                getchar(); getchar();
                break;
            case 2:
                // Wyświetlenie stanu konta
                printf("\nStan konta: %.2f zl\n", konto);
                getchar(); getchar();
                break;
            case 3:
                // Doładowanie konta
                printf("\nPodaj kwote do wplaty: ");
                scanf("%f", &wplata);
                if (wplata <= 0) {
                    printf("Kwota musi byc wieksza od zera!\n");
                } else {
                    konto += wplata;
                    printf("Doladowano konto o %.2f zl.\n", wplata);
                }
                getchar(); getchar();
                break;
            case 4:
                // Wyjście z programu
                printf("\nZamykanie programu...\n");
                break;

            default:
                // Niepoprawny wybór
                printf("Niepoprawny wybor!\n");
                getchar(); getchar();
        }
    } while (wybor != 4);
    return 0;
}
