//
// Created by Kamil Obrzut on 21.10.2026.
//
#pragma once
#include "ListFactory.h"
using namespace std;
/**
 * @file ListFactory.cpp
 * @brief Implementacja metody tworzącej listę dwukierunkową.
 */

///Metoda tworzy nowy pusty obiekt klasy List.
unique_ptr<List> ListFactory::createList() {
    return make_unique<List>();
}
