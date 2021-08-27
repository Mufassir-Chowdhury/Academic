#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *next;

    Node(int k) : value(k), next(NULL)    {}
};

class SinglyLinkedList{
    Node *head;
    Node *tail;

public:
    SinglyLinkedList()  : head(NULL), tail(NULL)    {}
    void push_back(int k);
    void push_front(int k);
    void pop_back();
    void pop_front();
    void print();
    int back();
    int front();
    int size();
    void insert(int k, int p);
    void remove(int k);
};

void SinglyLinkedList::push_back(int k){
    Node *newnode = new Node(k);

    if(head == NULL)
        head = tail = newnode;
    else{
        tail->next = newnode;
        tail = newnode;
    }
        
}

void SinglyLinkedList::pop_back(){
    if(head != NULL and head == tail){
        Node *cur = head;
        head = tail = NULL;
        delete cur;
    } else if(head != NULL){
        
    }
}

int SinglyLinkedList::back(){
    if(tail != NULL)
        return tail -> value;
}

int SinglyLinkedList::front(){
    if(head != NULL)
        return head -> value;
}

void SinglyLinkedList::print(){
    cout << "LIST: " << endl;
    Node *temp = head;
    while(temp){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SinglyLinkedList list;
    list.print();
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.print();

    return 0;
}