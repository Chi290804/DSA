#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;
        
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    
public:
    Queue() : front(nullptr), rear(nullptr) {}
    
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
    
    bool isEmpty() const {
        return front == nullptr;
    }
    
    void enqueue(int value) {
        Node* new_node = new Node(value);
        
        if (isEmpty()) {
            front = new_node;
            rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Empty" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            
            delete temp;
        }
    }
    
    int getFront() const {
        if (isEmpty()) {
            cout << "Empty" << endl;
            return -1;
        }
        
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