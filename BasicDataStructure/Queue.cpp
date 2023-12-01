#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    struct Node
    {
        int data;
        Node *next;

        Node(int data)
        {
            this->data = data;
            next = nullptr;
        }
    };

    Node *front;
    Node *rear;
    long length;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
        length = 0;
    };
    ~Queue(){};

    bool isEmpty()
    {
        return front = nullptr;
    }

    void enqueue(int k)
    {
        Node *new_node = new Node(k);

        if (isEmpty())
        {
            front = new_node;
            rear = new_node;
        }
        else
        {
            rear->next = new_node;
            rear = new_node;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            return;
        }

        else
        {
            Node *temp = front;
            front = front->next;
            if (front == nullptr)
            {
                rear = nullptr;
            }

            delete temp;
        }
    }

    int getFront() {
        return front->data;
    }

};

int main() {
    Queue queue;
    
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    cout << "Front element: " << queue.getFront() << endl;
    
    queue.dequeue();
    
    cout << "Front element after dequeue: " << queue.getFront() << endl;
    
    return 0;
}
