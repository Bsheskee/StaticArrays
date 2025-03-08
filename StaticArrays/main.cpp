//
//  main.cpp
//  Obsluga tablic w funkcjach i przekazywanie argumentu funkcji przez wskazniki
//  Managing static arrays in functions and passing function arguments by pointers
//  Created by Bartłomiej Białobrzewski on 08/03/2025.
//

#include <iostream>
using namespace std;

const int n = 4;
double A[n], B[n];

void wczytajDane(double A[], double B[], int n);
void wypiszDane(double A[], int n);
double iloczyn(double A[], int n);
double srednia(double B[], int n);
double maxElement(double A[], int n, int* index);

int main() {
    wczytajDane(A, B, n);
    wypiszDane(A, n);
    cout << "Iloczyn elementow tablicy A = " << iloczyn(A, n) << endl;
    cout << "Srednia elementow tablicy B = " << srednia(B, n) << endl;
    int index;
    cout << "Maksymalny element tablicy A = " << maxElement(A, n, &index) << ", ktory wystapil na indeksie " << index << endl;
    return 0;
}

void wczytajDane(double A[], double B[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Podaj " << i+1 << " element tablicy A: ";
        double element;
        cin >> element;
        A[i] = element;
    }
    for(int i = 0; i < n; i++) {
        cout << "Podaj " << i+1 << " element tablicy B: ";
        double element;
        cin >> element;
        B[i] = element;
    }
}
void wypiszDane(double A[], int n) {
    cout << "Elementy tablicy A to: ";
    for(int i = 0; i < n; i++) {
        cout << A[i];
        string interpunkcja = i < n-1 ? ", " : ".";
        cout << interpunkcja;
    }
    cout << endl;
}
double iloczyn(double A[], int n) {
    double iloczyn = 1.0;
    bool czyJestRozneOdZera = false;
    
    for(int i = 0; i < n; i++) {
        if (A[i] != 0) {
            iloczyn *= A[i];
            czyJestRozneOdZera = true;
        }

    }
    return czyJestRozneOdZera ? iloczyn : 0.0; //unikamy przypadkowego zwrocenia 1.0 w przypadku kiedy wszystkie elementy = 0
}
double srednia(double B[], int n) {
    if (n <= 0) {
        throw invalid_argument("n musi byc wieksze od 0 aby moc obliczyc srednia.");
    }
    double suma = 0.0;
    
    for (int i = 0; i < n; i++) {
        suma += B[i];
    }
    return suma / n;
}
double maxElement(double A[], int n, int* index) {
    if (n <= 0) {
        throw invalid_argument("n musi byc wieksze od 0.");
    }
    double maksElement = A[0];
    *index = 0;
    
    for (int i = 1; i < n; i++) {
        if (A[i] > maksElement) {
            maksElement = A[i];
            *index = i;
        }
    }
    return maksElement;
}
