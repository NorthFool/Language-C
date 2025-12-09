#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Funkcja sprawdza, czy PESEL jest poprawny
int poprawny_pesel(const char *pesel) {
    // Wagi używane do obliczania sumy kontrolnej
    int wagi[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    // PESEL musi mieć dokładnie 11 znaków
    if (strlen(pesel) != 11)
        return 0;
    // Sprawdzenie, czy wszystkie znaki to cyfry
    for (int i = 0; i < 11; i++) {
        // jeśli znak NIE jest cyfra to PESEL jest niepoprawny
        // isdigit - sprawdza czy to liczba dziesiętna
        if (!isdigit(pesel[i]))
            return 0;
    }
    int suma = 0;
    // Obliczanie sumy ważonej pierwszych 10 cyfr PESEL-u
    for (int i = 0; i < 10; i++) {
        suma += (pesel[i] - '0') * wagi[i];
        // pesel[i] - '0' zamienia znak ASCII cyfry na liczbę
    }
    // Obliczenie cyfry kontrolnej:
    // bierzemy ostatnią cyfrę wyniku 10 - (suma % 10)
    // i jeszcze raz mod 10 aby wynik był 0..9
    int kontrolna = (10 - (suma % 10)) % 10;
    // Porównanie obliczonej cyfry kontrolnej
    // z ostatnią cyfrą numeru PESEL
    return kontrolna == (pesel[10] - '0');
}
int main() {
    char pesel[20];
    printf("Podaj numer PESEL: ");
    scanf("%19s", pesel);

    if (poprawny_pesel(pesel))
        printf("PESEL jest poprawny.\n");
    else
        printf("PESEL NIE jest poprawny!\n");

    return 0;
}


