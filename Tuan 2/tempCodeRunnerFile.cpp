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