#include<iostream>
#include<map>
#include<set>

class Node{
public:
    int value;
    Node *previous, *next;
    Node(int val, Node *prev, Node *nex);
    ~Node();
};

class DoublyLinkedList{
private:
    int member = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
public:
    DoublyLinkedList(/* args */);
    void clear();
    int size();
    bool isEmpty();
    void addFirst(int element);
    void addLast(int element);
    void add(int element);
    int peekFirst();
    int peekLast();
    int removeFirst();
    int removeLast();
    int remove(Node *node);
    int removeAt(int index);
    bool removeValue (int element);
    int index(int element);
    bool contains(int element);
    void print();
    Node *getHead() const{
        return head;
    }
    ~DoublyLinkedList();
};

class Stack{
private:
    DoublyLinkedList list;
public:
    Stack();
    Stack(int element);
    int size();
    bool isEmpty();
    void push(int element);
    int pop();
    int peek();
    ~Stack();
};

class Queue{
private:
    DoublyLinkedList list;
public:
    Queue();
    Queue(int element);
    int size();
    bool isEmpty();
    int peek();
    int pop();
    void push(int element);
    ~Queue();
};

class PriorityQueue{
private:
    int heapSize = 0;
    int heapCapacity = 0;
    DoublyLinkedList heap;
    std::map<int, std::set<int> > map;
public:
    PriorityQueue();
    PriorityQueue(DoublyLinkedList elements);
    void add(int element);
    bool isEmpty();
    void clear();
    int size();
    int peek();
    int poll();
    int removeAt(int index);
    bool contains(int element);
    ~PriorityQueue();
};

PriorityQueue::PriorityQueue(){
    heapCapacity = 1;
}

PriorityQueue::PriorityQueue(DoublyLinkedList elements){
    heapCapacity = elements.size();
    for(Node *node = elements.getHead(); node != nullptr; node = node->next)
        add(node->value);
}

bool PriorityQueue::isEmpty(){
    return heapSize == 0;
}

void PriorityQueue::clear(){
    heap.clear();
    heapSize = 0;
    map.clear();
}

int PriorityQueue::size(){
    return heapSize;
}

int PriorityQueue::peek(){
    if(isEmpty()) return NULL;
    return heap.peekFirst();
}

int PriorityQueue::poll(){
    return removeAt(0);
}

bool PriorityQueue::contains(int element){
    if(element == NULL) return false;
    return map.count(element);
}

PriorityQueue::~PriorityQueue(){
}


Node::Node(int val, Node *prev, Node *nex){
    value = val;
    previous = prev;
    next = nex;
}

Node::~Node(){
}

DoublyLinkedList::DoublyLinkedList(/* args */){
}

void DoublyLinkedList::clear(){
    Node *trav = head;
    while(trav != nullptr){
        Node *nextptr = trav->next;
        trav->previous = trav->next = nullptr;
        trav->value = 0;
        trav = nextptr;
    }
    head = tail = trav = nullptr;
    member = 0;
}

int DoublyLinkedList::size(){
    return member;
}

bool DoublyLinkedList::isEmpty(){
    return size() == 0;
}

void DoublyLinkedList::addFirst(int element){
    if(isEmpty())
        head = tail = new Node(element, nullptr, nullptr);
    else {
        head->previous = new Node(element, nullptr, head);
        head = head->previous;
    }
    member++;
}

void DoublyLinkedList::addLast(int element){
    if(isEmpty())
        head = tail = new Node(element, nullptr, nullptr);
    else {
        tail->next = new Node(element, tail, nullptr);
        tail = tail->next;
    }
    member++;
}

void DoublyLinkedList::add(int element){
    addLast(element);
}

int DoublyLinkedList::peekFirst(){
    if(isEmpty())
        throw std::range_error("Empty list");    
    return head->value;
}

int DoublyLinkedList::peekLast(){
    if(isEmpty())
        throw std::range_error("Empty list");    
    return tail->value;
}

int DoublyLinkedList::removeFirst(){
    if(isEmpty())
        throw std::runtime_error("Empty LIst");
    int data = head->value;
    head = head->next;
    --member;
    if(isEmpty()) tail = nullptr;
    else head->previous = nullptr;
    return data;
}

int DoublyLinkedList::removeLast(){
    if(isEmpty())
        throw std::runtime_error("Empty List");
    
    int data = tail->value;
    tail = tail->previous;
    --member;

    if(isEmpty()) head = nullptr;
    else tail->next = nullptr;

    return data;
}

int DoublyLinkedList::remove(Node *node){
    if(node->previous == nullptr) return removeFirst();
    if(node->next == nullptr) return removeLast();
    node->next->previous = node->previous;
    node->previous->next = node->next;

    int data = node->value;

    node->value = 0;
    node = node->previous = node->next = nullptr;

    --member;

    return data;
}

int DoublyLinkedList::removeAt(int index){
    if( index < 0 || index >= member )
        throw std::invalid_argument("Invalid Argument");

    int i;
    Node *trav;

    if(index < member/2)
        for(i=0, trav = head; i != index; i++)
            trav = trav->next;
    else
        for(i = member-1, trav = tail; i!= index; i--)
            trav = trav->previous;

    return remove(trav);
}

bool DoublyLinkedList::removeValue(int element){
    Node *trav;

    for(trav = head; trav != nullptr; trav = trav->next){
        if(element == trav->value){
            remove(trav);
            return true;
        }
    }
    return false;
}

int DoublyLinkedList::index(int element){
    int index = 0;
    Node *trav = head;

    for(trav = head; trav != nullptr; trav = trav->next, index++)
        if(element == trav->value)
            return index;

    return -1;
}

bool DoublyLinkedList::contains(int element){
    return index(element) != -1;
}

void DoublyLinkedList::print(){
    Node *trav = head;
    std::cout << "List (" << size() << "): ";
    while(trav->next != nullptr){
        std::cout << trav->value << " ";
        trav = trav->next;
    }
    std::cout << trav->value << " " << std::endl;
}

DoublyLinkedList::~DoublyLinkedList(){
}

Stack::Stack(/* args */){
}

Stack::Stack(int element){
    push(element);
}

int Stack::size(){
    return list.size();
}

bool Stack::isEmpty(){
    return size() == 0;
}

void Stack::push(int element){
    list.addLast(element);
}

int Stack::pop(){
    if(isEmpty())
        throw std::invalid_argument("Empty Stack");
    return list.removeLast();
}

int Stack::peek(){
    if(isEmpty())
        throw std::invalid_argument("Empty Stack");
    return list.peekLast();
}

Stack::~Stack(){
}

Queue::Queue(){
}

Queue::Queue(int element){
    list.add(element);
}

int Queue::size(){
    return list.size();
}

bool Queue::isEmpty(){
    return list.size() == 0;
}

int Queue::peek(){
    if(isEmpty())
        throw std::runtime_error("Queue Empty");
    return list.peekFirst();
}

int Queue::pop(){
    if(isEmpty())
        throw std::runtime_error("Queue Empty");
    return list.removeFirst();    
}

void Queue::push(int element){
    list.add(element);
}

Queue::~Queue(){
}