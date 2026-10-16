//
// Created by Kamil Obrzut on 16.10.2026.
//
#pragma once
/**
 * @file Node.h
 * @brief Deklaracja klasy Node, która reprezentuje jeden węzęł listy dwukierunkowej.
 **/
/**
 * @class Node
 * @brief Reprezentuje pojedyńczy element klasy dwukierunkowej.
 *
 * Klasa przechowuje wartość całkowitą oraz wskaźniki na poprzedni i następny element listy.
 */
class Node {
    public:
    int data; ///< Wartość przechowywana w węźle.
    Node* next; ///< Wartość następna w węźle.
    Node* preview; ///<Wartość poprzednia w węźle.
/**
 * @brief konstruktor węzła.
 * @param value symbolizuje wartość węzła.
 */
    explicit Node(int value):data(value), next(nullptr), preview(nullptr) {}
};
