//
// Created by Kamil Obrzut on 21.10.2026.
//

#pragma once
#include "Node.h"
/**
 * @file ListIterator.h
 * @brief Deklaracja klasy iteratora listy dwukierunkowej.
 */

/**
 * @class ListIterator
 * @brief Klasa umożliwia poruszanie się po elementach listy.
 */

class ListIterator {
private:
 Node* current; ///< Wskaźnik na aktualny węzeł listy.
public:
 /**
     * @brief Konstruktor ustawiający początkowy węzeł iteratora.
     * @param start Wskaźnik na węzeł początkowy.
     */
 explicit ListIterator(Node* start);

 /**
  * @brief Sprawdza, czy iterator wskazuje na istniejący węzeł.
  * @return true, jeśli węzeł istnieje, w przeciwnym razie false.
  */
 bool isValid() const;

 /**
  * @brief Pobiera wartość aktualnego węzła.
  * @return Wartość przechowywana w aktualnym węźle.
  */
 int getValue() const;

 /**
  * @brief Przesuwa iterator na następny węzeł.
  */
 void next();

 /**
  * @brief Przesuwa iterator na poprzedni węzeł.
  */
 void previous();
};