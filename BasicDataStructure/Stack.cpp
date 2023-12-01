#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int size = 100;
    int top = 0;
    int stack[100];

public:
    Stack(/* args */)
    {
    }
    ~Stack()
    {
    }

    void push(int n)
    {
        if (isFull())
        {
            cout << "Full" << endl;
            return;
        }
        stack[top] = n;
        top++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Nah" << endl;
            return;
        }
        stack[top] = 0;
        top--;
    }

    bool isEmpty()
    {
        return top == 0 ? true : false;
    }
    bool isFull()
    {
        return top == size ? true : false;
    }

    int Top()
    {
        return stack[top - 1];
    }
    void print()
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

void DecToBin(int n)
{
    Stack *s = new Stack;
    while (n != 0)
    {
        int k = n % 2;
        n /= 2;
        s->push(k);
    }
    s->print();
}

/* void check(string a)
{
    for (auto char x:a) {
        if ()
    }
} */

void checkLarger(int a[], int n)
{
    Stack *s = new Stack();
    int b[n];
    for (int i = 0; i < n; i++)
    {
        if (s->isEmpty())
        {
            s->push(i);
        }
        else
        {
            while (!s->isEmpty() && a[i] > a[s->Top()])
            {
                b[s->Top()] = a[i];
                s->pop();
            }
            s->push(i);
        }
    }

    while (!s->isEmpty())
    {
        b[s->Top()] = -1;
        s->pop();
    }
    for (int i : b)
        cout << i << " ";
    cout << endl;
}

void theLargest(int a[]) {
    int n = a.size(), max = 0;
    Stack *s = new Stack();
    for ( int i = 0; i<n; i++) {
        if (s->isEmpty()) s->push(i);
        else {

        }
    }
}

int main()
{
    Stack *s = new Stack();
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(5);
    s->print();
    cout << s->Top() << endl;
    s->pop();
    s->print();
    DecToBin(20);
    int a[7] = {3, 4, 2, 5, 1, 6, 2}; 
    checkLarger(a, 7);
    return 0;
}
