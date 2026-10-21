//
// Created by Kamil Obrzut on 16.10.2026.
//
#include <iostream>
#include"List.h"
#include "ListFactory.h"
#include "ListIterator.h"
using namespace std;
/**
 * @brief Funkcja główna testująca działanie węzłów i listy.
 * Sprawdza tworzenie i łączenie węzłów oraz metody klas
 * dodawanie na początek, dodawanie na koniec
 * @return 0, jeśli program zakończył się poprawnie.
 */
int main() {
   /// Tworzenie listy za pomocą Factory.
    auto lista = ListFactory::createList();

    /// Dodawanie elementów na koniec listy.
    cout << "Dodawanie na koniec:" << endl;
    lista->PushBack(5);
    lista->PushBack(15);
    lista->PushBack(20);
    lista->printNormal();
    /// Dodawanie elementu na początek listy.
    cout << "Dodawanie na poczatek:" << endl;
    lista->PushFront(2);
    lista->printNormal();

    /// Dodawanie elementu pod wskazany indeks.
    cout << "Dodawanie pod indeks 2:" << endl;
    lista->pushAt(2, 10);
    lista->printNormal();
    /// Wyświetlanie listy w odwrotnej kolejności.
    cout << "Wyswietlanie od konca:" << endl;
    lista->printReverse();

    /// Wyświetlanie następnego elementu.
    cout << "Nastepny element po indeksie 2:" << endl;
    lista->printNext(2);

    /// Wyświetlanie poprzedniego elementu.
    cout << "Poprzedni element przed indeksem 2:" << endl;
    lista->printBack(2);

    /// Test iteratora od początku listy.
    cout << "Iterator od poczatku:" << endl;

    ListIterator iterator = lista->begin();

    while (iterator.isValid()) {
        cout << iterator.getValue() << " ";
        iterator.next();
    }
    cout << endl;

    /// Test iteratora od końca listy.
    cout << "Iterator od konca:" << endl;

    ListIterator reverseIterator = lista->rbegin();

    while (reverseIterator.isValid()) {
        cout << reverseIterator.getValue() << " ";
        reverseIterator.previous();
    }
    cout << endl;

    /// Usuwanie elementu pod wskazanym indeksem.
    cout << "Usuwanie pod indeksem 2:" << endl;
    lista->deleteAt(2);
    lista->printNormal();

    /// Usuwanie pierwszego elementu listy.
    cout << "Usuwanie z poczatku:" << endl;
    lista->deleteFront();
    lista->printNormal();

    /// Usuwanie ostatniego elementu listy.
    cout << "Usuwanie z konca:" << endl;
    lista->deleteBack();
    lista->printNormal();

    /// Czyszczenie całej listy.
    cout << "Czyszczenie listy:" << endl;
    lista->clear();
    lista->printNormal();

    return 0;
}