// updated by sara on 29/4/2023.
#include <iostream>

using namespace std;

template<typename elementType>
class CircularLikedList {
    struct Node {
        elementType data;
        Node *next;

        Node(elementType data) : data(data), next(nullptr) {}
    };
    Node *head;
    int CLLsize;
public:
    CircularLikedList() {
        head = nullptr;
        CLLsize = 0;
    }

   void insertAtHead(elementType element) {
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

   void insertAtEnd(elementType element) {
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

    void insertAt(elementType element, int index) {
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
        CLLsize++;
    }

    void removeAtHead() {
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
    void removeAtEnd() {
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

    void removeAt(int index) {
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

    elementType retrieveAt(int index) {
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

    void replaceAt(int newElement, int index) {
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

    bool isExist(elementType element) {
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

    bool isItemAtEqual(elementType element, int index){
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

    void swap(int firstItemIdx, int secondItemIdx) {
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

    int doubleLinkedListSize() const {
    return CLLsize;
    }

    bool isEmpty() const {
    return CLLsize == 0;
    }

    void clear() {
    while (!isEmpty()) {
            removeAtHead();
        }
    }

void print() {
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
};

int main(){
    CircularLikedList<int> CLL;
    CLL.insertAtHead(4);
    CLL.insertAt(9,1);
    CLL.insertAtEnd(6);
    CLL.isEmpty();
    CLL.print();
    CLL.doubleLinkedListSize();
    CLL.isItemAtEqual(4,0);
    CLL.isExist(6);
    CLL.removeAtHead();
    CLL.removeAt(2);
    CLL.removeAtEnd();
    CLL.insertAtHead(4);
    CLL.insertAt(10,1);
    CLL.insertAtEnd(8);
    CLL.swap(0,2);
    CLL.print();
    CLL.retrieveAt(0);
    CLL.replaceAt(20,1);
    CLL.clear();
}
