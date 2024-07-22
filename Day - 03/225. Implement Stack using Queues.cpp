/**
 *  @file: 225. Implement Stack using Queues.cpp
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/implement-stack-using-queues
 *  @level: Easy
 *  @date: 16-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class MyStack
{
public:
    queue<int> Q1, Q2;

    MyStack()
    {
    }

    void push(int x)
    {
        Q2.push(x);
        while (!empty())
        {
            Q2.push(Q1.front());
            Q1.pop();
        }
        Q1.swap(Q2);
    }

    int pop()
    {
        int top1 = Q1.front();
        Q1.pop();
        return (top1);
    }

    int top()
    {
        return Q1.front();
    }

    bool empty()
    {
        return Q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */