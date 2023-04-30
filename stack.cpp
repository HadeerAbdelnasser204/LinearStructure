#include <iostream>
#include <string>
#include <cassert>
using namespace std;
template <class T>
class Stack
{
    int top;
    int length;
    int maxSize;
    T *arr;

public:
    Stack(int size = 10)
    {
        if (size <= 0)
            maxSize = 100;
        else
            maxSize = size;
        top = -1;
        length = 0;
        arr = new T[maxSize];
    }
    bool isEmpty()
    {
        if (top < 0)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == maxSize - 1)
            return true;
        else
            return false;
    }
    void push(T element)
    {
        if (isFull())
        {
            cout << "stack is full" << endl;
        }
        else
        {
            top++;
            length++;
            arr[top] = element;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            T element = arr[top];
            top--;
            length--;
        }
    }
    int stackSize()
    {
        return length;
    }
    void print()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void clear()
    {
        top = -1;
        length = 0;
    }
    T first()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return false;
        }
        else
        {
            return arr[top];
        }
    }
    bool ArePair(char open, char close)
    {
        if (open == '(' && close == ')')
            return true;
        else
            return false;
    }
    int Parentheses(string expersion)
    {
        Stack s(expersion.length());
        int sum = 0;
        for (int i = 0; i < expersion.length(); i++)
        {
            if (expersion[i] == '(')
            {
                s.push(expersion[i]);
                // sum++;
            }
            else if (expersion[i] == ')')
            {
                {
                    if (s.isEmpty() || !ArePair(s.first(), expersion[i]))
                    {
                    }
                    else
                    {
                        s.pop();
                        sum++;
                    }
                }
            }
        }
        return sum * 2;
    }
    int operatorsWeight(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    void infixToPostfix(string s)
    {

        Stack<char> st;
        string result;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ')
                result += c;
            else if (c == '(')
                st.push('(');
            else if (c == ')')
            {
                while (st.first() != '(')
                {
                    result += st.first();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.isEmpty() && operatorsWeight(s[i]) <= operatorsWeight(st.first()))
                {
                    result += st.first();
                    st.pop();
                }
                st.push(c);
            }
        }
        while (!st.isEmpty())
        {
            result += st.first();
            st.pop();
        }

        cout << result << endl;
    }
};
