//
// Created by Hadeer on 4/18/2023.
//

#ifndef DS_A2_DLL_H
#define DS_A2_DLL_H

struct Node{
    int data;
    Node * next;
    Node * pre;
};
class DoubleLinkedList {
private:
    int size;
    Node * head;
    Node * tail;
    public:
     DoubleLinkedList();
     void insertAtHead(int element);
     void insertAtTail(int element);
     void insertAt(int element, int index);
     void insertAfter(Node *pre_node, int data);
     void removeAtHead();
     void removeAtTail();
     void removeAt(int index);
     int retrieve(int index);
     void replaceAt(int newElement, int index);
     bool isExist(int element);
     bool isItemEqual(int element, int index);
     void swap(int firstItemIdx, int secondItemIdx);
     void reverse();
     bool isEmpty() const;
     int doubleLinkedListSize() const;
     void clear ();
     void forwardTraversal ();
     void backwardTraversal();


};


#endif //DS_A2_DLL_H
