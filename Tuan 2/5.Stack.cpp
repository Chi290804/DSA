#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> stack;
    
public:
    Stack() {}
    
    bool isEmpty() const {
        return stack.empty();
    }
    
    void push(int value) {
        stack.push_back(value);
    }
    
    void pop() {
        if (!isEmpty()) {
            stack.pop_back();
        } else {
            std::cout << "Empty" << std::endl;
        }
    }
    
    int top() const {
        if (!isEmpty()) {
            return stack.back();
        } else {
            std::cout << "Empty" << std::endl;
            return -1;
        }
    }
    
    void printStack() const {
        for (const auto& element : stack) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    std::cout << "Stack elements: ";
    stack.printStack();
    
    stack.pop();
    
    std::cout << "Top element after pop: " << stack.top() << std::endl;
    
    return 0;
}