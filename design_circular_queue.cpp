#include<iostream>

using namespace std;


/*
Design your implementation of the circular queue. The circular queue is a linear data structure 
in which the operations are performed based on FIFO (First In First Out) principle, and the last
position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. 
In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a 
space in front of the queue. But using the circular queue, we can use the space to store new values.
*/

class Node{
    public: 
        int val = 0;
        Node* next = nullptr;
        Node() : val(0), next(nullptr){};
        Node(int x) : val(x), next(nullptr){};
};

class MyCircularQueue {
public:

    int size = 0;
    int count = 0;

    Node* front = nullptr;  

    Node* getRearNode()
    {
        if(front == nullptr) return front;
        Node* curr = front;
        // move pointer from front around to the end
        while(curr->next != front){
            curr=curr->next;
        }
        return curr;
    }

    // Initializes the object with the size of the queue to be k
    MyCircularQueue(int k) {
        size = k;
    }
    
    // inserts an element into the circular queue. Return true if the operation is successful.
    bool enQueue(int value) {
        if(count < size )
        {
            // add new element
            Node* addition = new Node(value);
            if(front == nullptr){
                front = addition; 
                front->next = front; 
            }
            else
            {
                Node* addition = new Node(value);
                Node* curr = getRearNode();
                curr->next = addition; 
                addition->next = front; 
            }

            count++;

            return true;
        }
        return false;
    }
    
    // Deletes an element from the circular queue. Return true if the operation is successful.
    bool deQueue() {
        // FIFO
        if(front == nullptr) return false;

        if(front == front->next)
        {
            delete front;
            front = nullptr;
            count--;
            return true;
        }
        else
        {
            Node* rear = getRearNode();
            rear->next = front->next;
            Node* old_front = front;
            front = front->next;
            delete old_front;
            count--;
            return true;
        }
        return false;
    }

    // Gets the front item from the queue. If the queue is empty, return -1    
    int Front() {
        if(front != nullptr) return front->val;
        return -1;
    }
    
    // Gets the last item from the queue. If the queue is empty, return -1.
    int Rear() {
        Node* rear = getRearNode();
        if(rear == nullptr) return -1;
        return rear->val;
    }
    
    // Checks whether the circular queue is empty or not.
    bool isEmpty() { 
        return (front == nullptr);
    }
    
    // Checks whether the circular queue is full or not.
    bool isFull() {
        return (count == size);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

 int main()
 {
    MyCircularQueue q = MyCircularQueue(4);
    q.enQueue(1); 
    q.enQueue(2); 
    q.enQueue(14);
    q.enQueue(44); 
    cout << "front " << q.Front() << endl;
    cout << "rear " << q.Rear() << endl;
    q.deQueue();
    cout << "front " << q.Front() << endl;
    cout << "rear " << q.Rear() << endl;
    q.deQueue();
    cout << "front " << q.Front() << endl;
    cout << "rear " << q.Rear() << endl;
    q.deQueue();
    cout << "front " << q.Front() << endl;
    cout << "rear " << q.Rear() << endl;
    q.deQueue();
    cout << "front " << q.Front() << endl;
    cout << "rear " << q.Rear() << endl;


    return 0;
 }