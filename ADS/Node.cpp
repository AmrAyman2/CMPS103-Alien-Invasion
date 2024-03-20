//This is the node class
template <typename T>
class Node {
public:
    T data; //the data or object that the node contains
    Node<T>* next;

    // Constructors
    Node() : next(nullptr) {} // Default constructor
    Node(T& newData) : data(newData), next(nullptr) {} // Constructor with data or object

};