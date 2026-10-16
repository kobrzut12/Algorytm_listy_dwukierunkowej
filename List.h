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
    List():head(nullptr), tail(nullptr) {} ///<Konstruktor tworzący pustą listę.
    /**
     * @brief Destruktor, który służy do zwalniania pamięci.
     */
    ~List() {
        Node* current = head;
    while (current != nullptr) {
        Node* nextNode=current->next;
        delete current;
        current = nextNode;
    }
    }
    ///Zapobiega możliwości kopiowania węzłów.
    List(const List&)=delete;
    ///Blokuje przypisanie kopiujące węzły.
    List& operator=(const List&)=delete;

    /**
     * @brief Metoda służy do dodawania nowego elementu na początek listy.
     * @param value Wskazuje wartość.
     */
     void  PushFront(int value) {
        Node* newNode=new Node(value);
        if (head == nullptr) {
            head=newNode;
            tail=newNode;
        }else {
            newNode->next=head;
            head->preview=newNode;
            head=newNode;
        }
    }

    /**
     * @brief Metoda służy do dodawania elementu na koniec listy.
     * @param value daje wartość elementowi na końcu listy
     */
    void PushBack(int value) {
        Node* newNode=new Node(value);
        if (tail==nullptr) {
            tail=newNode;
            head=newNode;
        }else {
          newNode->preview=tail;
            tail->next=newNode;
            tail=newNode;
        }
    }

    /**
     * @brief Wyświetla całą liste od początku do końca
     */
    void printNormal()const {
        Node*current=head;
        while (current!=nullptr) {
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }

    /**
     * @brief Metoda służy do usuwania węzła z przodu listy dwukierunkowej.
     */
    void deleteFront() {
         if (head==nullptr) {
             return;
         }
         Node* Delete=head;
         head=head->next;
         if (head!=nullptr) {
             head->preview=nullptr;
         }
         else {
             tail=nullptr;
         }
         delete Delete;
     }
};