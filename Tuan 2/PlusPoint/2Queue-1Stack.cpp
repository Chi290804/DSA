#include<bits/stdc++.h>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* front;
    Node* rear;
    int length = 0;
    
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
        return (length == 0);
    }
    int getLength() {
        return length;
    }
    int getFront() {
        if (isEmpty()){
            cout << "Empty";
            return -1;
        }
        return front ->data ;
    }
    void Push(int val){
        Node* t = new Node;
        t->data=val;
        t->next=NULL;
        length ++;
        if (length == 1 ) { 
            front = t;
            rear = t;
            return;
        }

        rear->next = t;
        rear = t;
    }

    void Pop(){
        if (isEmpty()){
            return;
        }
        length--;

        Node* t = front->next;
        delete front;
        front = t;
    }
};

Queue q1,q2;

int Remove(){
    while(q1.getLength() > 1){
        q2.Push(q1.getFront());
        q1.Pop();
    }
    int t = q1.getFront();
    q1.Pop();

    while(!q2.isEmpty()){
        q1.Push(q2.getFront());
        q2.Pop();
    }

    return t;
}

void Final(){
    int n;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        if ( s == "push" ){
            int data;
            cin >>data;
            q1.Push(data);
        }
        else 
        cout << Remove() <<" ";
    }
}

int main(){
    Final();
    return 0;
}