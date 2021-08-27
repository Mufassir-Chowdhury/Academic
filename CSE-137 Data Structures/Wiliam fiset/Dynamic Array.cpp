#include<iostream>

class Array{
private:
    int *arr;
    int len = 0;
    int capacity = 0;
public:
    Array();
    Array(int capacity);
    int size();
    bool isEmpty();
    int get(int index);
    int *getAddress(int index);
    void set(int index, int element);
    void clear();
    void add(int element);
    int removeAt(int index);
    void print();
    bool remove(int element);
    int indexOf(int element);
    bool contains(int element);
    ~Array();
};

Array::Array(){
    // arr = new int(16);
    int *array{new int[16]{}};
    arr = array;
    capacity = 16;
}
Array::Array(int capacity){
    int *array{new int[capacity]{}};
    arr = array;
    capacity = capacity;
}

int Array::size(){
    return len;
}

bool Array::isEmpty(){
    return size() == 0;
}

int Array::get(int index){
    return arr[index];
}

int *Array::getAddress(int index){
    return (arr+index);
}

void Array::set(int index, int element){
    arr[index] = element;
}

void Array::clear(){
    for(int i=0; i<capacity; i++)
        arr[i] = NULL;
    len = 0;
}

void Array::add(int element){
    if(len +1 >= capacity){
        if(capacity == 0) capacity = 1;
        else capacity *= 2;
        int *array{ new int[capacity]{} };
        for(int i=0; i<len; i++)
            array[i] = arr[i];
        arr = array;
    }
    arr[len++] = element;
}

int Array::removeAt(int index){
    if(index >= len || index < 0)
        throw std::invalid_argument("Invalid Index");
    int data = arr[index];
    int *array{ new int[len-1]{} };
    for(int i=0, j=0; i<len; i++, j++){
        if(i==index) j--;
        else array[j] = arr[i];
    }
    arr = array;
    capacity = --len;
    return data;
}

void Array::print(){
    for(int i=0; i<len; i++)
        std::cout << get(i) << " ";
    std::cout << std::endl;
}

bool Array::remove(int element){
    for(int i=0; i<len; i++)
        if(arr[i] == element)
            return removeAt(i);
    return false;
}

int Array::indexOf(int element){
    for(int i=0; i<len; i++)
        if(arr[i] == element)
            return i;
    return -1;
}

bool Array::contains(int element){
    return indexOf(element) != -1;
}

Array::~Array(){
}


int main(){
    Array arr;
    for(int i=0; i<=15; i++)
        arr.set(i, i+1);
    for(int i=0; i<=15; i++)
        std::cout << arr.get(i) << " ";
    std::cout << std::endl;
    arr.clear();
    arr.print();
    arr.add(3);
    arr.add(2);
    arr.add(4);
    arr.add(20);
    arr.print();
    arr.removeAt(2);
    arr.print();    
    arr.remove(1);
    arr.remove(2);
    arr.print();
    std::cout << arr.indexOf(20) << std::endl;
    std::cout << arr.contains(20) << std::endl;

    return 0;
}