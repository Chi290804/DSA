#include <bits/stdc++.h>
using namespace std;

class Stack{
private:
    struct Node
    {
    int data;
    Node* next;
    };

    Node* top;
    int length = 0;
public:

    bool isEmpty(){
        return (length = 0);
    }

    int getTop(){
        if ( isEmpty()) {
            cout << "Empty";
            return -1;
        }
        return top->data;
    }

    void Insert(int val){
        Node* t = new Node;
        t->data=val;

        length ++;

        if (length == 1){
            top = t;
            top ->next = NULL;
            return;
        }
        t->next = top;
        top = t;
    }
    
    void Pop(){
        if (isEmpty()) 
            return;

        length--;
        Node* t = top->next;
        delete top;
        top = t ;
    }
};

Stack s1, s2;

int dequeue(){
    while(!s1.isEmpty()){
        s2.Insert(s1.getTop());
        s1.Pop();
    }

    int ans = s2.getTop();
    s2.Pop();

    while (!s2.isEmpty())
    {
        s1.Insert(s2.getTop());
        s2.Pop();   
    }
    return ans;
}

void Final(){
    int n; 
    cin>>n;
    while (n--)
    {
        string t;
        cin >> t;
        if ( t == "enqueue"){
            int val;
            cin>>val;
            s1.Insert(val);
        }
        else
        cout << dequeue() <<" ";
    }
}

int main(){
    Final();
    return 0;
}