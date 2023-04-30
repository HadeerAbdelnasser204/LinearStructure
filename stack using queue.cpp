#include <iostream>
#include <queue>
using namespace std;
class Stack
{
    // Two inbuilt queues
    queue<int> q1, q2, q;

public:
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop()
    {
        if (q1.empty())
            return;
        q1.pop();
    }

    int top()
    {
        if (q1.empty())
            return;
        return q1.front();
    }

    int size()
    {
        return q1.size();
    }
};
