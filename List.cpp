
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
   clear();
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
///Dodawanie pod wskazany index.
void List::pushAt(int index, int value) {
    if (index<0) {
        return;
    }
    if (index==0) {
        PushFront(value);
        return;
    }
    Node*current=head;
    int i=0;

    while (current!=nullptr && i<index) {
        current=current->next;
        i++;
    }
    if (i!=index) {
        return;
    }
    if (current==nullptr) {
        PushBack(value);
        return;
    }
    Node*nextNode=new Node(value);

    nextNode->next=current;
    nextNode->preview=current->preview;

    current->preview->next=nextNode;
    current->preview=nextNode;
}
///Wyświetlanie listy w odwrotnej kolejności.

void List::printReverse() const {
    Node*current=tail;
    while (current!=nullptr) {
        cout<<current->data<<" ";
        current=current->preview;
    }
    cout<<endl;
}

///Wyświetlanie następnego elementu listu.
void List::printNext(int index) const {
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
        cout<<"Nie ma elementu pod tym indeksem"<<endl;
        return;
    }
    if (current->next==nullptr) {
        cout<<"Brak nastepnego elementu"<<endl;
        return;
    }
    cout<<current->next->data<<endl;
}

///Służy do wyświetlania poprzedniego elementu w liście.
void List::printBack(int index) const {
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
        cout<<"Nie ma elementu pod tym indeksem"<<endl;
        return;
    }
    if (current->preview==nullptr) {
        cout<<"Brak poprzedniego elementu"<<endl;
        return;
    }
    cout<<current->preview->data<<endl;
}

///Czyszczenie listy.
void List::clear() {
    Node*current=head;
    while (current!=nullptr ) {
        Node* nextNode=current->next;
        delete current;
        current=nextNode;
    }
    head=nullptr;
    tail=nullptr;
}


/// Tworzenie iteratora od początku listy.
ListIterator List::begin() const {
    return ListIterator(head);
}

/// Tworzenie iteratora od końca listy.
ListIterator List::rbegin() const {
    return ListIterator(tail);
}

