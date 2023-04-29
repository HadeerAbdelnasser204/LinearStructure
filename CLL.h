//
// Created by Hadeer on 4/18/2023.
//

#ifndef DS_A2_CIRCULARLIKEDLIST_H
#define DS_A2_CIRCULARLIKEDLIST_H

template<typename elementType>
class CircularLikedList {
    struct Node {
        elementType data;
        Node *next;

        Node() : data(data), next(nullptr) {}
    };
private:
       Node *head;
       int CLLsize;
public:

    CircularLikedList();

    void insertAtHead(elementType element);

    void insertAtEnd(elementType element);

    void insertAt(elementType element, int index);

    void removeAtHead();

    void removeAtEnd();

    void removeAt(int index);

    elementType retrieveAt(int index);

    void replaceAt(elementType newElement, int index);

    bool isExist(elementType element);

    bool isItemAtEqual(elementType element, int index);

    void swap(int firstItemIdx, int secondItemIdx);

    bool isEmpty() const;

    int doubleLinkedListSize() const;

    void clear();

    void print();


};


#endif //DS_A2_CIRCULARLIKEDLIST_H
