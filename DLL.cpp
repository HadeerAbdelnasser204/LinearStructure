/
// Created by Hadeer on 4/18/2023.
//
#include <iostream>
#include <cstdlib>
#include "DLL.h"

using namespace std;

DoubleLinkedList::DoubleLinkedList() {
    size = 0;
    head = tail = nullptr;

}

void DoubleLinkedList::insertAtHead(int element) {
    Node *newNode = new Node();
    newNode->data = element;
    newNode->pre = nullptr;
    if (head == nullptr) {
        head = tail = newNode;

    } else {
        newNode->next = head;
        head->pre = newNode;
        head = newNode;
    }
    size++;
}

void DoubleLinkedList::insertAtTail(int element) {
    Node *newNode = new Node;
    newNode->data = element;
    newNode->next = nullptr;
    newNode->pre = nullptr;

    if (head == nullptr) {
        head = tail = newNode;

    } else {
        newNode->pre = tail;
        tail->next = newNode;
        tail = newNode;
    }

    size++;
}

void DoubleLinkedList::insertAt(int element, int index) {
    Node *newNode = new Node;
    newNode->data = element;
    if (index == 0) {
        insertAtHead(element);

    } else if (index >= size) {
        insertAtTail(element);
    } else {
        Node *current = head;
        int count = 0;
        while (count <= index - 1) {
            current = current->next;
            count++;

        }
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;
}

void DoubleLinkedList::insertAfter(Node *pre_node, int data) {
    if(pre_node == nullptr){
        return;
    }
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = pre_node->next;
    pre_node->next = newNode;
    newNode->pre = pre_node;

    if (newNode->next != nullptr){
        newNode->next->pre = newNode;
    }

}

void DoubleLinkedList::removeAtHead() {
    if (size == 0) {
        return;
    } else if (size == 1) {
        delete[] head;
        head = tail = nullptr;
    } else {
        Node *temp = head;
        head = head->next;
        delete[] temp;
    }
    size--;

}

void DoubleLinkedList::removeAtTail() {
    if (size == 0) {
        return;
    } else if (size == 1) {
        delete[] head;
        head = tail = nullptr;
    } else {
        Node *temp = tail;
        tail->pre->next = nullptr;
        tail = temp->pre;
        delete[] temp;
    }
    size--;
}

void DoubleLinkedList::removeAt(int index) {
    if (index == 0)
        removeAtHead();

    else if (index == size - 1) {
        removeAtTail();
    } else {

        int counter = 0;
        Node *current = head;
        while (counter < index - 1) {
            current = current->next;
            counter++;
        }

        Node *target = current->next;
        current->next = target->next;
        free(target);
        size--;
    }

}

int DoubleLinkedList::retrieve(int index) {
    if (index == 0) {
        return head->data;
    } else if (index == size - 1) {
        return tail->pre->data;
    } else {
        Node *current = head;
        int count = 0;
        while (count <= index - 1) {
            current = current->next;
            count++;
        }
        return current->data;
    }
}

void DoubleLinkedList::replaceAt(int newElement, int index) {
    Node *current = head;
    int count = 0;
    while (count <= index - 1) {
        current = current->next;
        count++;

    }

    current->data = newElement;

}

bool DoubleLinkedList::isExist(int element) {
    bool found = false;
    int counter = 0;
    Node *node = new Node;
    node->data = element;
    Node *current = head;
    while (current->next != tail) {
        if (current->data == node->data) {
            found = true;
            break;
        } else {
            counter++;
        }
        current = current->next;
    }

    if (counter == size) {
        found = false;
    }
    return found;
}

bool DoubleLinkedList::isItemEqual(int element, int index) {
    bool equal = false;
    int counter = 0;
    Node *node = new Node;
    node->data = element;
    Node *current = head;
    while (counter <= index - 1) {
        current = current->next;
        counter++;
    }
    if (current->data == node->data) {
        equal = true;
    } else {
        equal = false;

    }
    return equal;
}

void DoubleLinkedList::swap(int firstItemIdx, int secondItemIdx) {
    int counter1 = 0;
    int counter2 = 0;
    Node *current = head;
    Node *current1 = head;
    while (counter1 != firstItemIdx - 1) {
        current = current->next;
        counter1++;
    }
    while (counter2 != secondItemIdx) {
        current1 = current1->next;
        counter2++;

    }
    Node *temp = new Node;
    temp->next = current->next;
    current->next = current1->next;
    current1->next = temp->next;

}

int DoubleLinkedList::doubleLinkedListSize() const {
    return size;
}

void DoubleLinkedList::reverse() {
    Node *temp = nullptr;
    Node *current = head;
    while (current != nullptr) {
        temp = current->pre;
        current->pre = current->next;
        current->next = temp;
        current = current->pre;
    }
    if (temp != nullptr) {
        head = temp->pre;
    }
}

bool DoubleLinkedList::isEmpty() const {
    return size == 0;
}

void DoubleLinkedList::clear() {
    size = 0;
}

void DoubleLinkedList::forwardTraversal() {
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void DoubleLinkedList::backwardTraversal() {
    Node *current = tail;
    while (current != head->pre) {
        cout << current->data << " ";
        current = current->pre;
    }
    cout << endl;
}