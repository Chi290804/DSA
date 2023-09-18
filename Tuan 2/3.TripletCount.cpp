#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

int count_triplets(const vector<int>& numbers) {
    int count = 0;
    Node* head = nullptr;
    Node* current = nullptr;

    for (int i = 0; i < numbers.size(); ++i) {
        Node* new_node = new Node(numbers[i]);
        
        if (head == nullptr) {
            head = new_node;
            current = head;
        } else {
            current->next = new_node;
            new_node->prev = current;
            current = new_node;
        }
    }
    
    current = head->next;

    while (current->next->next != nullptr) {
        if (current->data + current->prev->data + current->next->data == 0) {
            count++;
        }
        current = current->next;
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    
    int result = count_triplets(numbers);
    cout << result << endl;
    
    return 0;
}