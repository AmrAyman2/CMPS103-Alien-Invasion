#include "Node.cpp"
template <typename T>
class Queue {
private:
    Node<T>* frontPtr;
    Node<T>* rearPtr;

public:
    // Constructor
    Queue() : frontPtr(nullptr), rearPtr(nullptr) {}

    // Destructor (deletes all nodes in it)
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return frontPtr == nullptr;
    }

    // Enqueue operation to add an element to the rear of the queue
    void enqueue(T& newData) {
        Node<T>* newNode = new Node<T>(newData);
        if (isEmpty()) {
            frontPtr = newNode;
            rearPtr = newNode;
        }
        else {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
    }

    // Dequeue operation to remove an element from the front of the queue
    void dequeue() {
        if (!isEmpty()) {
            Node<T>* temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
            if (frontPtr == nullptr) {
                rearPtr = nullptr;
            }
        }
        else {
            return;
        }
    }

    // Get the element at the front of the queue without removing it
    void peek(T* frntEntry) const {
        frntEntry = frontPtr;
    }

};