
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Queue
{
private:
    int size;
    vector<T> Vqueue;

public:
    explicit Queue(int sz)
    {
        size = sz;
    }

    void enqueue(T element)
    {
        Vqueue.push_back(element);
    }

    T dequeue()
    {
        int ele = Vqueue.front();
        Vqueue.erase(Vqueue.begin());
        size--;
        return ele;
    }

    T first()
    {
        return Vqueue.front();
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int queueSize()
    {
        return size;
    }

    void clear()
    {
        size = 0;
    }
    void print()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << Vqueue[i] << " ";
        }
        cout << endl;
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

