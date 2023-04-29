// Created by Hadeer on 4/18/2023.
//
#include <cstdlib>
#include <iostream>
#include "CircularLikedList.h"

using namespace std;

CircularLikedList::CircularLikedList() {
    head = nullptr;
    CLLsize = 0;
}

template<typename elementType>
void CircularLikedList::insertAtHead(elementType element) {
   Node *newNode = new Node(element);
        if (head == nullptr) {
            newNode->next = newNode;
        } else {
            Node *tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            newNode->next = head;
            tail->next = newNode;
        }
        head = newNode;
        CLLsize++;
}

template<typename elementType>
void CircularLikedList::insertAtEnd(elementType element) {
   if (isEmpty()) {
            insertAtHead(element);
            return;
        }

        Node *newNode = new Node(element);
        Node *tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = head;

    CLLsize++;
}

template<typename elementType>
void CircularLikedList::insertAt(elementType element, int index) {
   if (index < 0 || index > CLLsize) {
            std::cout << "Invalid index. Insertion failed." << std::endl;
            return;
        }

        if (index == 0) {
            insertAtHead(element);
            return;
        }

        if (index == CLLsize) {
            insertAtEnd(element);
            return;
        }

        Node *newNode = new Node(element);
        Node *prev = nullptr;
        Node *current = head;
        int count = 0;

        while (count < index) {
            prev = current;
            current = current->next;
            count++;
        }

        prev->next = newNode;
        newNode->next = current;
    }
    CLLsize++;
}

void CircularLikedList::removeAtHead() {
    if (isEmpty()) {
            std::cout << "The list is empty. Removal failed." << std::endl;
            return;
        }

        if (CLLsize == 1) {
            delete head;
            head = nullptr;
        } else {
            Node *tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            Node *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    CLLsize--;

}
void CircularLikedList::removeAtEnd() {
         if (isEmpty()) {
            std::cout << "The list is empty. Removal failed." << std::endl;
            return;
        }

        if (CLLsize == 1) {
            removeAtHead();
            return;
        }

        Node *prev = nullptr;
        Node *current = head;
        while (current->next != head) {
            prev = current;
            current = current->next;
        }

        prev->next = head;
        delete current;
        CLLsize--;
}


void CircularLikedList::removeAt(int index) {
    if (isEmpty()) {
            return;
        }

        if (index < 0 || index >= CLLsize) {
            return;
        }

        if (index == 0) {
            removeAtHead();
            return;
        }

        if (index == CLLsize - 1) {
            removeAtEnd();
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        int count = 0;

        while (count < index) {
            prev = current;
            current = current->next;
            count++;
        }

        prev->next = current->next;
        delete current;
        CLLsize--;
}

template<typename elementType>
elementType CircularLikedList::retrieveAt(int index) {
    if (isEmpty()) {
            return -1;
        }

        if (index < 0 || index >= CLLsize) {
            return -1;
        }

        Node* current = head;
        int count = 0;

        while (count < index) {
            current = current->next;
            count++;
        }

        return current->data;
}

template<typename elementType>
void CircularLikedList::replaceAt(int newElement, int index) {
    if (isEmpty()) {
            return;
        }

        if (index < 0 || index >= CLLsize) {
            return;
        }

        Node* current = head;
        int count = 0;

        while (count < index) {
            current = current->next;
            count++;
        }

        current->data = newElement;
}

template<typename elementType>
bool CircularLikedList::isExist(elementType element) {
    if (isEmpty()) {
            return false;
        }

        Node* current = head;
        do {
            if (current->data == element) {
                return true;
            }
            current = current->next;
        } while (current != head);

        return false;
}

template<typename elementType>
bool CircularLikedList::isItemAtEqual(elementType element, int index){
    if (isEmpty()) {
            return false;
        }

        if (index < 0 || index >= CLLsize) {
            return false;
        }

        Node* current = head;
        int count = 0;

        while (count < index) {
            current = current->next;
            count++;
        }

        return current->data == element;
}

void CircularLikedList::swap(int firstItemIdx, int secondItemIdx) {
    if (isEmpty() || CLLsize < 2) {
            return;
        }

        if (firstItemIdx < 0 || firstItemIdx >= CLLsize || secondItemIdx < 0 || secondItemIdx >= CLLsize) {
            return;
        }

        if (firstItemIdx == secondItemIdx) {
            return; // No need to swap, same indices
        }

        Node* prevFirst = nullptr;
        Node* currentFirst = head;
        int countFirst = 0;

        while (countFirst < firstItemIdx) {
            prevFirst = currentFirst;
            currentFirst = currentFirst->next;
            countFirst++;
        }

        Node* prevSecond = nullptr;
        Node* currentSecond = head;
        int countSecond = 0;

        while (countSecond < secondItemIdx) {
            prevSecond = currentSecond;
            currentSecond = currentSecond->next;
            countSecond++;
        }

        // Update next pointers of previous nodes
        if (prevFirst) {
            prevFirst->next = currentSecond;
        } else {
            head = currentSecond;
        }

        if (prevSecond) {
            prevSecond->next = currentFirst;
        } else {
            head = currentFirst;
        }

        // Update next pointers of swapped nodes
        Node* temp = currentFirst->next;
        currentFirst->next = currentSecond->next;
        currentSecond->next = temp;
}

int CircularLikedList::doubleLinkedListSize() const {
    return CLLsize;
}
bool CircularLikedList::isEmpty() const {
    return CLLsize == 0;
}

void CircularLikedList::clear() {
    while (!isEmpty()) {
            removeAtHead();
        }
}

void CircularLikedList::print() {
    if (isEmpty()) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
}
