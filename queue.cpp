#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
template <class T>
class Queue
{
private:
    int last;
    int top;
    int length;
    T *arr;
    int maxSize;

public:
    Queue(int size = 10)
    {
        if (size <= 0)
            maxSize = 100;
        else
            maxSize = size;

        top = 0;

        arr = new T[maxSize];
        last = maxSize - 1;
        length = 0;
    }
    int isEmpty()
    {
        return length == 0;
    }
    bool isFull()
    {
        return length == maxSize;
    }
    void enqueue(T Element)
    {
        if (isFull())
        {
            cout << "Full Queue";
        }
        else
        {
            last = (last + 1) % maxSize;
            arr[last] = Element;
            length++;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Empty Queue";
        }
        else
        {
            top = (top + 1) % maxSize;
            --length;
        }
    }

    void print()
    {
        if (!isEmpty())
        {
            for (int i = top; i != last; i = (i + 1) % maxSize)
            {
                cout << arr[i] << " ";
            }
            cout << arr[last];
        }
        else
            cout << "Empty Queue";
    }

    ~Queue()
    {
        delete[] arr;
    }

    int queueSize()
    {
        return length;
    }
    void clear()
    {
        top = 0;
        last = maxSize - 1;
        length = 0;
    }
    int first()
    {
        return arr[top];
    }
    void sort()
    {
        int n = length;
        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i++)
            {
                T temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];
                arr[j] = temp;
            }
        }
    }
    void Binary(int n)
    {
        string s;
        while (n)
        {
            if (n & 1)
                s += '1';
            else
                s += '0';
            n >>= 1;
        }
        reverse(s.begin(), s.end());
        int data = stoi(s);
        this->enqueue(data);
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(3);
    q.enqueue(15);
    q.enqueue(2);
    q.enqueue(4);
    q.sort();
    q.print();
}
