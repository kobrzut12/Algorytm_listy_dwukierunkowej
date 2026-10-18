
#include "List.h"
#include <iostream>

/**
 * @file List.cpp
 * @brief Implementacja metod klasy List.
 */

/// Konstruktor.
List::List() : head(nullptr), tail(nullptr) {}

/// Destruktor.
List::~List() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

/// Dodawanie na początek.
void List::PushFront(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head->preview = newNode;
        head = newNode;
    }
}

/// Dodawanie na koniec.
void List::PushBack(int value) {
    Node* newNode = new Node(value);

    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->preview = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

/// Wyświetlanie listy.
void List::printNormal() const {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

/// Usuwanie pierwszego elementu.
void List::deleteFront() {
    if (head == nullptr) {
        return;
    }

    Node* toDelete = head;
    head = head->next;

    if (head != nullptr) {
        head->preview = nullptr;
    }
    else {
        tail = nullptr;
    }

    delete toDelete;
}

/// Usuwanie ostatniego elementu.
void List::deleteBack() {
    if (tail == nullptr) {
        return;
    }

    Node* toDelete = tail;
    tail = tail->preview;

    if (tail != nullptr) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }

    delete toDelete;
}
