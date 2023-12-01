#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
private:
    struct Node
    {
        int priority;
        int data;
        Node *next;
        Node(){};
        Node(int k, int priority)
        {
            this->data = k;
            this->next = nullptr;
        }
    };

    Node *front;
    Node *rear;
    long length;

public:
    PriorityQueue() = default;
    ~PriorityQueue() = default;
    bool isEmpty()
    {
        return front == nullptr;
    }
    void enqueue(int k, int priority)
    {
        Node *newNode = new Node(k, priority);
        if (isEmpty() || priority <= front->priority)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            Node *rear = front;
            while (rear->next != nullptr && rear->next->priority <= priority)
            {
                rear = rear->next;
            }
            newNode->next = rear->next;
            rear->next = newNode;
        }
    }

    void dequeue()
    {
        if (isEmpty())
            return;
        Node *temp = front;
        front = front->next;
        delete temp;
    }

    int peek()
    {
        return front->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Priority queue is empty." << endl;
            return;
        }

        Node *temp = front; // Use a temporary pointer variable to traverse the queue

        while (temp != nullptr)
        {
            cout << temp->data << " "; // Print the data
            temp = temp->next;         // Move to the next node
        }
        cout << endl;
    }
};

int main()
{
    int choice = 0, item, priority;

    PriorityQueue *q = new PriorityQueue;

    while (choice != 4)
    {
        cin >> choice;
        switch ((choice))
        {
        case 1:
            cin >> item;
            cin >> priority;
            q->enqueue(item, priority);
        case 2:
            q->dequeue();
        case 3:
            q->display();
        case 4:
            break;
        default:
            cout << "chose\n";
        }
    }
    q->display();
    return 0;
}
