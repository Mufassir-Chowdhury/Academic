#include<iostream>
#include"Containers.hpp"

int main(){
    DoublyLinkedList list;
    for(int i=0; i<10; i++)
        list.add(i);
    list.print();
    list.addFirst(1);
    list.addLast(2);
    list.print();
    std::cout << list.contains(1) << std::endl;
    std::cout << list.index(2) << std::endl;
    std::cout << list.peekFirst() << " " << list.peekLast() << std::endl;
    list.print();
    list.removeAt(1);
    list.print();
    list.removeFirst();
    list.print();
    list.removeLast();
    list.print();
    list.removeValue(7);
    list.print();
    std::cout << list.isEmpty() << " " << list.size() << std::endl;
    list.clear();
    std::cout << list.isEmpty() << " " << list.size() << std::endl;
    
    Stack stack;
    std::cout << stack.isEmpty() << " " << stack.size() << std::endl;
    for(int i=0; i<10; i++)
        stack.push(i);
    std::cout << stack.isEmpty() << " " << stack.size() << std::endl;
    std::cout << stack.size() << " " << stack.peek() << std::endl;
    stack.pop();
    stack.pop();
    stack.pop();
    std::cout << stack.size() << " " << stack.peek() << std::endl;

    Queue queue;
    std::cout << queue.isEmpty() << " " << queue.size() << std::endl;
    for(int i=0; i<10; i++)
        queue.push(i);
    std::cout << queue.isEmpty() << " " << queue.size() << std::endl;
    std::cout << queue.size() << " " << queue.peek() << std::endl;
    queue.pop();
    queue.pop();
    queue.pop();
    std::cout << queue.size() << " " << queue.peek() << std::endl;
    return 0;
}