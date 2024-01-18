#include <iostream>
#include <new>

void statyczna() {
    double tablica[1000000];
    std::cout << "Zmienna statyczna utworzona. Kliknij aby kontynuować...\n";
    std::cin.get();
}

void dynamiczna() {
    double* tablica = new (std::nothrow) double[1000000];
    if (!tablica) {
        std::cout << "Nie udało się zaalokować pamięci!\n";
    } else {
        std::cout << "Zmienna dynamiczna utworzona. Kliknij aby kontynuować...\n";
        std::cin.get();
        delete[] tablica;
    }
}

int main() {
    statyczna();
    std::cout << "Naciśnij dowolny klawisz, aby wywołać funkcję dynamiczną...\n";
    std::cin.get();
    dynamiczna();
    return 0;
}
