#include <stdio.h> 
#include <stdbool.h> 
 
// funkcja co sprawdza czy liczba jest pierwsza 
bool czyPierwsza(int liczba) { 
    if (liczba < 2) return false; // jak mniejsze niż 2 to na pewno nie pierwsza 
    for (int i = 2; i * i <= liczba; i++) { 
        if (liczba % i == 0) return false; 
    } 
    return true; 
} 
 
int main() { 
    int a, b; 
    float c, d; 
 
    printf("Podaj liczbe calkowita a: "); 
    scanf("%d", &a); 
    printf("Podaj liczbe calkowita b: "); 
    scanf("%d", &b); 
    printf("Podaj liczbe zmiennoprzecinkowa c: "); 
    scanf("%f", &c); 
    printf("Podaj liczbe zmiennoprzecinkowa d: "); 
    scanf("%f", &d); 
 
    float wyniki[12]; // tabliza gdzie zapisuje wyniki 
 
    // wykonuje działania 
    wyniki[0] = a + b; 
    wyniki[1] = a - b; 
    wyniki[2] = a * b; 
    wyniki[3] = a / b; 
    wyniki[4] = a + c; 
    wyniki[5] = a - c; 
    wyniki[6] = a * c; 
    wyniki[7] = a / c; 
    wyniki[8] = c + d; 
    wyniki[9] = c - d; 
    wyniki[10] = c * d; 
    wyniki[11] = c / d; 
 
    printf("\nWyniki dzialan:\n"); 
    for (int i = 0; i < 12; i++) { 
        printf("wyniki[%d] = %.2f\n", i, wyniki[i]); 
    } 
 
    // teraz sprawdzam parzystość 
    printf("\nParzystosc wynikow (tylko liczby calkowite sa sprawdzane, reszta nieparzysta):\n"); 
    for (int i = 0; i < 12; i++) { 
        if (wyniki[i] == (int)wyniki[i]) { 
            if ((int)wyniki[i] % 2 == 0) { 
                printf("wyniki[%d] = %.2f parzysty\n", i, wyniki[i]); 
            } else { 
                printf("wyniki[%d] = %.2f nieparzysty\n", i, wyniki[i]); 
            } 
        } else { 
            // jak niecałkowita to z automatu uznaję ją za „nieparzystą” 
            printf("wyniki[%d] = %.2f nieparzysty\n", i, wyniki[i]); 
        } 
    } 
 
    int pierwsze[25]; // liczby pierwsze z zakresu 1–100 
    int index = 0; 
 
    // wypisuję wszystkie liczby pierwsze od 2 do 100 
    printf("\nLiczby pierwsze od 1 do 100:\n"); 
    for (int i = 2; i <= 100; i++) { 
        if (czyPierwsza(i)) { 
            printf("%d ", i); 
            pierwsze[index++] = i; // zapisuję, bo potem porównuję 
        } 
    } 
    printf("\n"); 
 
    // sprawdzam które wyniki z tablicy są liczbami pierwszymi 
    printf("\nSprawdzenie, ktore wyniki sa liczbami pierwszymi:\n"); 
    for (int i = 0; i < 12; i++) { 
        // znowu tylko całkowite i dodatnie wyniki mają sens 
        if (wyniki[i] == (int)wyniki[i] && wyniki[i] > 0) { 
            int w = (int)wyniki[i]; 
            bool pierwsza = false; 
 
            // porównuję ze znalezionymi wcześniej liczbami pierwszymi 
            for (int j = 0; j < index; j++) { 
                if (w == pierwsze[j]) { 
                    pierwsza = true; 
                    break; 
                } 
            } 
 
            if (pierwsza) { 
                printf("wyniki[%d] = %.2f jest liczba pierwsza\n", i, wyniki[i]); 
            } else { 
                printf("wyniki[%d] = %.2f nie jest liczba pierwsza\n", i, wyniki[i]); 
            } 
        } else { 
            // jak nie całkowita albo <= 0 t nie pierwsza 
            printf("wyniki[%d] = %.2f nie jest liczba pierwsza\n", i, wyniki[i]); 
        } 
    } 
    printf("\nWcisnij ENTER aby zakonczyc..."); 
    getchar(); 
    getchar(); 
    return 0; 
}
