#include <iostream>
#include <cassert>
#include <vector>
#include "SLL.h"
using namespace std;
SingleLinkedList :: SingleLinkedList () {
    size = 0;
    head = tail = nullptr;
}
void SingleLinkedList ::  insertAtHead(int element) {
    Node *newNode = new Node();
    newNode -> data = element;
    if (head == nullptr && tail == nullptr) {
        head = tail = newNode;

    } else {
        newNode->next = head;
        head = newNode;
    }
    size++;

}
void SingleLinkedList:: insertAtTail(int element) {
    Node *newNode = new Node;
    newNode->data = element;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        tail = newNode;
    }
    size++;
}

void SingleLinkedList:: insertAt(int element, int index) {
    Node *newNode = new Node;
    newNode->data = element;
    if (index == 0) {
        insertAtHead(element);

    } else if (index >= size) {
        insertAtTail(element);
    } else {
        Node *current = head;
        int count = 0;
        while (count != index - 1) {
            current = current->next;
            count++;

        }
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;

}


void SingleLinkedList :: removeAtHead() {
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
void SingleLinkedList :: removeAt(int index) {
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
int SingleLinkedList::retrieve(int index){
    Node *current = head;
    int count = 0;
    while (count <= index - 1) {
        current = current->next;
        count++;

    }
    return current->data;
}

void  SingleLinkedList:: replaceAt(int newElement, int index) {
    Node *current = head;
    int count = 0;
    while (count <= index - 1) {
        current = current->next;
        count++;

    }

    current->data = newElement;

}

bool SingleLinkedList :: isExist(int element) {
    bool found = false;
    int counter = 0;
    Node *node = new Node;
    node->data = element;
    Node *current = head;
    while (current->next != tail) {
        if (current->data == node->data) {
            found = true;
            break;
        }
        else {
            counter++;
        }
        current = current->next;
    }

    if (counter == size) {
        found = false;
    }
    return found;

}

bool SingleLinkedList::isItemAtEqual(int element, int index) {
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

void SingleLinkedList :: swap(int firstItemIdx, int secondItemIdx) {
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

bool SingleLinkedList::isEmpty() {
    return size == 0;
}

int SingleLinkedList::linkedListSize() {
    return size;
}

void SingleLinkedList :: clear() {
    size = 0;
    delete head;
    delete tail;
}
void SingleLinkedList ::print() {
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
//problems.















/*________________________2)Merge________________________________*/

class Solution {
public:
    Node* mergeTwoLists(Node* l1, Node* l2) {
        Node* dummy = new Node(0);
        Node* tail = dummy;
        while (l1 && l2) {
            if (l1->data < l2->data) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy->next;
    }
};
