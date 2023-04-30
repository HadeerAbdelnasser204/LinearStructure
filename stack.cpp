//
// Created by saraw on 4/30/2023.
//

//
// Created by A plus on 4/19/2023.
//
#include <iostream>
#include <vector>
using namespace std;
template<class T>
class Stack {
private:
    vector<T> s;
    int size;
public:
    Stack();
    explicit Stack(int sz){
        size = sz;
    }
    void push(T element) {
        s.push_back(element);
    }

    T pop() {
        T ele = s.front();
        s.erase(s.begin());
        return ele;
    }

    T top() {
        return s.front();
    }

    bool isEmpty() {
        return size == 0;
    }

    int stackSize() {
        return size;
    }

    void clear() {
        size = 0;
    }
    void print(){
        for (int i = size - 1; i >= 0 ; --i) {
            cout << s[i] << " ";
        }
        cout << endl;
    }

    // probelm 3 infix to postfix stack
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

// problem longest valid parentheses stack
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
};


