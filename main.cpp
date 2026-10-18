//
// Created by Kamil Obrzut on 16.10.2026.
//
#include <iostream>
#include"List.h"
using namespace std;
/**
 * @brief Funkcja główna testująca działanie węzłów i listy.
 * Sprawdza tworzenie i łączenie węzłów oraz metody klas
 * dodawanie na początek, dodawanie na koniec
 * @return 0, jeśli program zakończył się poprawnie.
 */
int main() {
   List lista;
   cout<<"Test push front"<<endl;
   lista.PushFront(20);
   lista.PushFront(10);
   lista.printNormal();

   cout<<"Test push back"<<endl;
   lista.PushBack(10);
   lista.PushBack(33);
   lista.printNormal();

   return 0;
}