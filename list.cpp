#include <iostream>
#include <cassert>
using namespace std;
template<class T>
class ArrayList {
private:
    int size = 0;
    int maxSize;
    int *list;
public:
    ArrayList() {

    }

    ArrayList(int size) {
        if (size < 0) {
            cout << "Array size must be positive" << endl;
            maxSize = 100;
        } else {
            maxSize = size;
        }
        size = 0;
        list = new int[maxSize];
        assert(list != nullptr);

    }

    void insert(T element) {
        if (size >= maxSize) { //Full
            cout << "Can't add a new element" << endl;
        } else {
            list[size] = element;
            size++;
        }
    }

    void insertAt(T element, int index) {
        if (index < 0 || index >= maxSize) {
            cout << "Sorry, out of range" << endl;
        } else if (size >= maxSize) { //Full
            cout << "Can't add a new element" << endl;
        } else {
            for (int i = size; i > index; i--) {
                list[i] = list[i - 1];
            }
            list[index] = element;

            size++;
        }
    }

    T retrieveAt(int index) {
        cout << list[index] << endl;
    }


    void removeAt(int index) {
        if (index < 0 || index >= maxSize) {
            cout << "Sorry, out of range" << endl;
        } else if (size == 0) {
            cout << "list is empty" << endl;
        } else {
            for (int i = index; i < size; ++i) {
                list[i] = list[i + 1];
            }
            size--;
        }
    }

    void replaceAt(int newElement, int index) {
        list[index] = newElement;
    }

    bool isItemAtEqual(int element, int index) {
        if (list[index] == element) {
            return true;
        } else
            return false;
    }

    bool isEmpty() const {
        if (size == 0)
            return true;
        else
            return false;
    }

    bool isFull() const {
        if (size == maxSize) {
            return true;
        } else
            return false;
    }

    int listSize() const {
        return size;
    }

    int maxListSize() const {
        return maxSize;

    }

    void clear() {
        size = 0;
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            cout << list[i] << " ";
        }
        cout << endl;
    }

};

int main(){
    ArrayList<int> list;
    list.insert(2);
    list.insert(4);
    list.insert(6);
    list.insert(8);
    list.isFull();
    list.maxListSize();
    list.removeAt(0);
    list.isEmpty();
    list.print();
    list.clear();

}
