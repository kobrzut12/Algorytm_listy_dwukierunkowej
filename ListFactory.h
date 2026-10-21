//
// Created by Kamil Obrzut on 21.10.2026.
//

#pragma once
#include<memory>
#include "List.h"
using namespace std;

/**
 *@file List.h
 * @brief Deklaracja klasy Factory.
 */
/**
 *@class ListFactory.
 *@brief Klasa służąca do tworzenia obiektów listy dwukierunkowej.
 */

class ListFactory {
public:
    /**
     * @brief Tworzy nową pustą listę dwukierunkową.
     * @return Wskaźnik zarządzający utworzonym obiektem listy.
     */
    static unique_ptr<List> createList();
};