//
// Created by Kamil Obrzut on 21.10.2026.
//

#pragma once
#include "ListIterator.h"
#include<stdexcept>
using namespace std;
/**
 * @file ListIterator.cpp
 * @brief Implementacja metod iteratora listy dwukierunkowej.
 */

///Konstruktor iteratora.
ListIterator::ListIterator(Node *start):current(start){}

///Sprawdzenie, czy iterator wskazuje na węzeł.
bool ListIterator::isValid() const {
    return current!=nullptr;
}

/// Odczyt wartości aktualnego węzła.
int ListIterator::getValue() const {
    if (current == nullptr) {
        throw out_of_range("Iterator nie wskazuje na wezel.");
    }
    return current->data;
}

/// Przejście do następnego węzła.
void ListIterator::next() {
    if (current!=nullptr) {
        current=current->next;
    }
}

///Przejście do poprzedniego węzła.
void ListIterator::previous() {
    if (current!=nullptr) {
        current=current->preview;
    }
}


