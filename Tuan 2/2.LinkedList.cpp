#include <bits/stdc++.h>
using namespace std;
 
class Node {
    public:
    int data;
    Node* next;

    Node ( int v ) {
        data = v;
        next = nullptr;
    }
};
 
class LinkedList
{
private:
    Node *head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insert ( int p, int x) {
        Node * node = new Node(x);
        if ( p == 0){
            node -> next = head;
            head = node;
        }
        else {
            Node* curr;
            Node* prev;
            int pos = 0;
            while (curr && pos < p){
                prev = curr;
                curr = curr -> next;
                pos ++;
            }
            if ( curr = nullptr){
                prev -> next = node;
            }
            else {
                prev -> next = node;
                node -> next = curr;
            }
        }
    }

        void deleteNode(int p) {
        if (head == nullptr) {
            return;
        }

        if (p == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* curr = head;
            Node* prev = nullptr;
            int pos = 0;

            while (curr && pos < p) {
                prev = curr;
                curr = curr->next;
                pos++;
            }

            if (curr == nullptr) {
                return;
            }

            prev->next = curr->next;
            delete curr;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Linked List is empty" << endl;
        } else {
            Node* curr = head;

            while (curr) {
                cout << curr->data << " ";
                curr = curr->next;
            }

            cout << endl;
        }
    }
};

int main()
{
    LinkedList ll;
    ll.insert(0,4);
    ll.insert(1,2);
    ll.insert(2,4);
    ll.display();
}