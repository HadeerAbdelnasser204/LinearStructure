// Created by Hadeer on 4/18/2023.
// updated by sara on 29/4/2023.
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
    Node() : next(nullptr){}
};

template <typename elementType>
class SingleLinkedList
{
    Node* head;
    Node* tail;
    int size;
public:

    SingleLinkedList()
    {
        size = 0;
        head = tail = nullptr;
    }
    void insertAtHead(elementType element)
    {
        Node *newNode = new Node();
        newNode->data = element;
        if (head == nullptr && tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    void insertAtTail(elementType element)
    {
        Node *newNode = new Node;
        newNode->data = element;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void insertAt(elementType element, int index)
    {
        Node *newNode = new Node;
        newNode->data = element;
        if (index == 0)
        {
            insertAtHead(element);
        }
        else if (index >= size)
        {
            insertAtTail(element);
        }
        else
        {
            Node *current = head;
            int count = 0;
            while (count != index - 1)
            {
                current = current->next;
                count++;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

    void removeAtHead()
    {
        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            delete[] head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete[] temp;
        }
        size--;
    }
    void removeAtTail()
    {
        if (head == nullptr)
            return;
        else
        {
            Node *temp = head, *prevNode;
            if (head->next == nullptr)
                head = nullptr;
            else
            {
                while (temp->next != nullptr)
                {
                    prevNode = temp;
                    temp = temp->next;
                }
                prevNode->next = nullptr;
            }
            delete temp;
        }
    }
    void removeAt(int index)
    {
        if (index == 0)
            removeAtHead();

        else if (index == size - 1)
        {
            removeAtTail();
        }
        else
        {

            int counter = 0;
            Node *current = head;
            while (counter < index - 1)
            {
                current = current->next;
                counter++;
            }

            Node *target = current->next;
            current->next = target->next;
            free(target);
            size--;
        }
    }
    elementType retrieve(int index)
    {
        Node *current = head;
        int count = 0;
        while (count <= index - 1)
        {
            current = current->next;
            count++;
        }
        return current->data;
    }

    void replaceAt(elementType newElement, int index)
    {
        Node *current = head;
        int count = 0;
        while (count <= index - 1)
        {
            current = current->next;
            count++;
        }

        current->data = newElement;
    }

    bool isExist(elementType element)
    {
        bool found = false;
        int counter = 0;
        Node *node = new Node;
        node->data = element;
        Node *current = head;
        while (current->next != tail)
        {
            if (current->data == node->data)
            {
                found = true;
                break;
            }
            else
            {
                counter++;
            }
            current = current->next;
        }

        if (counter == size)
        {
            found = false;
        }
        return found;
    }

    bool isItemAtEqual(elementType element, int index)
    {
        bool equal = false;
        int counter = 0;
        Node *node = new Node;
        node->data = element;
        Node *current = head;
        while (counter <= index - 1)
        {
            current = current->next;
            counter++;
        }
        if (current->data == node->data)
        {
            equal = true;
        }
        else
        {
            equal = false;
        }
        return equal;
    }

    void swap(int firstItemIdx, int secondItemIdx)
    {
        int counter1 = 0;
        int counter2 = 0;
        Node *current = head;
        Node *current1 = head;
        while (counter1 != firstItemIdx - 1)
        {
            current = current->next;
            counter1++;
        }
        while (counter2 != secondItemIdx)
        {
            current1 = current1->next;
            counter2++;
        }
        Node *temp = new Node();
        temp->next = current->next;
        current->next = current1->next;
        current1->next = temp->next;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int linkedListSize()
    {
        return size;
    }

    void clear()
    {
        head = tail = NULL;
        size = 0;
    }
    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    Node *getLinkedListHead()
    {
        return head;
    }
    void CombineNodesBetweenZeros()
    {
        Node *cur = head->next;
        SingleLinkedList newList;
        int sum = 0;
        int temp = size;
        while (cur != NULL)
        {
            if (cur->data == 0)
            {
                newList.insertAtTail(sum);
                sum = 0;
            }
            else
            {
                sum += cur->data;
            }
            cur = cur->next;
            this->clear();
            Node *copyhead = newList.getLinkedListHead();
            while (copyhead != NULL)
            {
                this->insertAtTail(copyhead->data);
                copyhead = copyhead->next;
            }
        }
    }
};

// problems.

/*________________________2)Merge________________________________*/

 class Solution
 {
 public:
     Node *mergeTwoLists(Node *l1, Node *l2)
     {
         Node *dummy = new Node();
         Node *tail = dummy;
         while (l1 && l2)
         {
             if (l1->data < l2->data)
             {
                 tail->next = l1;
                 l1 = l1->next;
             }
             else
             {
                 tail->next = l2;
                 l2 = l2->next;
             }
             tail = tail->next;
         }
         tail->next = l1 ? l1 : l2;
         return dummy->next;
     }
 };

int main()
{
     SingleLinkedList<int> ll;
     ll.insertAtHead(6);
     ll.insertAt(1,9);
     ll.insertAtTail(10);
     ll.replaceAt(30,1);
     ll.isExist(30);
     ll.swap(0,1);
     ll.isItemAtEqual(6,0);
     ll.retrieve(0);
     ll.print();
     ll.removeAtTail();
     ll.removeAt(0);
     ll.clear();


    SingleLinkedList<int> l;
    l.insertAtTail(0);
     l.insertAtTail(1);
     l.insertAtTail(3);
     l.insertAtTail(0);
     l.insertAtTail(4);
     l.insertAtTail(5);
     l.insertAtTail(3);
     l.insertAtTail(0);
     l.CombineNodesBetweenZeros();
     l.print();


        // mergeTwoLists
        Solution solution;
        Node* l1 = new Node(1);
        l1->next = new Node(2);
        l1->next->next = new Node(4);
        Node* l2 = new Node(1);
        l2->next = new Node(3);
        l2->next->next = new Node(4);
        Node* result = solution.mergeTwoLists(l1, l2);
        while (result) {
            cout << result->data << " ";
            result = result->next;
        }
        cout << endl;

}
