#pragma once
#include "Node.h"

/**
 *@file List.h
 * @brief Deklaracja klasy listy dwukierunkowej.
 */

/**
 * @class List
 * @brief Klasa zarządza listą.
 *
 *  Elementy tworzone dynamicznie oraz przechowuje wskaźniki na pierwszy i ostatni węzeł.
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

    ///Zapobiega możliwości kopiowania całej listy.
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
    /**
     * @brief Usuwa element znajdujący się pod wskazanym indeksem.
     * @param index Indeks elementu do usunięcia, liczony od zera.
     */
    void deleteAt(int index);

    /**
     *@brief Metoda dodaje nowy węzeł pod wskazanym indeksem..
     *@param index wskazuje indeks.
     *@param value wskazuje wartość.
     */
    void pushAt(int index, int value);

    /**
     *@brief Metoda służy do wyświetlania listy w odwrotnej kolejności.
     */
    void printReverse()const;

    /**
     *@brief Metoda służy do wyświetlania następnego elementu listy.
    *@param index wskazuje indeks.
    */

    void printNext(int index)const;
    /**
         *@brief Metoda służy do wyświetlania poprzedniego elementu listy.
        *@param index wskazuje indeks.
        */
    void printBack(int index)const;
/**
 *@brief Metoda służy do czyszczenia całej listy.
 */
    void clear();
};
