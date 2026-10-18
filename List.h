#pragma once

#include <iostream>
#include "Node.h"
using namespace std;

/**
 *@file List.h
 * @brief Implementacja listy dwukierunkowej.
 */

/**
 * @class List
 * @brief Klasa zarządza listą.
 *
 *  Elementy tworzony dynamicznie oraz przechowuje wskaźniki na pierwszy i ostatni węzęł.
 */

class List {
    private:
    Node* head; ///<Wskaźnik na pierwszy element listy.
    Node* tail; ///<Wskaźnik na ostatni element listy.
public:
    List(); ///<Konstruktor tworzący pustą listę.
    /**
     * @brief Destruktor, który służy do zwalniania pamięci.
     */
    ~List();

    ///Zapobiega możliwości kopiowania węzłów.
    List(const List&)=delete;
    ///Blokuje przypisanie kopiujące węzły.
    List& operator=(const List&)=delete;

    /**
     * @brief Metoda służy do dodawania nowego elementu na początek listy.
     * @param value Wskazuje wartość.
     */
     void  PushFront(int value);

    /**
     * @brief Metoda służy do dodawania elementu na koniec listy.
     * @param value daje wartość elementowi na końcu listy
     */
    void PushBack(int value);

    /**
     * @brief Wyświetla całą liste od początku do końca
     */
    void printNormal()const;

    /**
     * @brief Metoda służy do usuwania węzła z przodu listy dwukierunkowej.
     */
    void deleteFront();

    /**
     * @brief Metoda służy do usuwania węzła z tyłu listy dwukierunkowej.
     */
    void deleteBack();
};