//
// Created by Hadeer on 4/18/2023.
//

#ifndef DS_A2_CIRCULARLIKEDLIST_H
#define DS_A2_CIRCULARLIKEDLIST_H


class CircularLikedList {
    struct Node {
        int data = 0;
        Node *next = nullptr;
        Node *pre = nullptr;
    };
private:
    int size;
    Node *head;
    Node *tail;
public:

    CircularLikedList();

    void insertAtHead(int element);

    void insertAtEnd(int element);

    void insertAt(int element, int index);

    void removeAtHead();

    void removeAtEnd();

    void removeAt(int index);

    int retrieve(int index);

    void replaceAt(int newElement, int index);

    bool isExist(int element);

    bool isItemEqual(int element, int index);

    void swap(int firstItemIdx, int secondItemIdx);

    bool isEmpty() const;

    int doubleLinkedListSize() const;

    void clear();

    void print();


};


#endif //DS_A2_CIRCULARLIKEDLIST_H
