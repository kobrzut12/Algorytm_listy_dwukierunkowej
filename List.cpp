
#include "List.h"
#include <iostream>
using namespace std;
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
        cout << current->data << " ";
        current = current->next;
    }

  cout <<endl;
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

void List::deleteAt(int index) {
if (index<0) {
    return;
}
    Node*current=head;
    int i=0;
    while (current!=nullptr && i<index) {
        current=current->next;
        i++;
    }
    if (current==nullptr) {
        return;
    }
    if (current==head) {
        deleteFront();
        return;
    }
    if (current==tail) {
        deleteBack();
        return;
    }
    current->preview->next=current->next;
    current->next->preview=current->preview;
    delete current;
}
