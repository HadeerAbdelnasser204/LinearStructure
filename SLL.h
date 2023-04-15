// Single Linked List - DataStructure Assignment.
// Created by Hadeer Abdelnasser on 4/15/2023.
//

#ifndef DS_A2_SLL_H
#define DS_A2_SLL_H

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node * next;
};

class SingleLinkedList{
private:
    Node * head;
    Node * tail;
    int size;
public:
    SingleLinkedList();
    void insertAtHead (int element);
    void insertAtTail (int element);
    void insertAt (int element, int index);
    void removeAtHead ();
    void removeAtTail ();
    void removeAt (int index);
    int retrieve(int index);
    void replaceAt (int newElement, int index);
    bool isItemAtEqual(int element, int index);
    void swap(int firstItemIdx, int secondItemIdx);
    bool isExist (int element);
    bool isEmpty ();
    int linkedListSize ();
    void clear ();
    void print ();


};
#endif //DS_A2_SLL_H
