#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> array){
    for(auto i: array)
        cout << i <<  " ";
    cout << endl;
} 

int main(){
    vector<int> numbers;
    numbers = {1, 2, 3, 4, 5};
    print(numbers);
    vector<int> copy_of_numbers(numbers);
    print(copy_of_numbers);
    vector<int> generated(50, 4);
    print(generated);
    vector<int> subset_of_numbers(numbers.begin() + 2, numbers.end());
    print(subset_of_numbers);
    vector<int> another_copy;
    another_copy = numbers;
    print(another_copy);
    cout << "Size: " << numbers.size() << " | Max Size: " << numbers.max_size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    cout << "Is numbers empty: " << numbers.empty() << endl;
    numbers.shrink_to_fit();
    cout << "Capacity after shrink: " << numbers.capacity() << endl;

    for(size_t i=0; i<numbers.size(); i++)
        cout << numbers[i] << " \n"[i==numbers.size()-1];

    for(size_t i=0; i<numbers.size(); i++)
        cout << numbers.at(i) << " \n"[i==numbers.size()-1];
        
    cout << numbers.back() - numbers.front() << endl;
    int *array = numbers.data();
    for(size_t i =0; i<numbers.size(); i++)
        cout << array[i] << " ";
    cout << endl;

    another_copy.assign(4, 100);
    print(another_copy);
    another_copy.insert(another_copy.begin(), 4);
    print(another_copy);
    another_copy.insert(another_copy.begin()+2, 4, 50);
    print(another_copy);
    another_copy.insert(another_copy.end(), numbers.begin(), numbers.end());
    print(another_copy);
    another_copy.pop_back();
    another_copy.push_back(25);
    print(another_copy);
    another_copy.erase(another_copy.end()-2);
    print(another_copy);
    another_copy.erase(another_copy.begin()+1, another_copy.begin()+3);

    another_copy.swap(numbers);
    print(numbers);
    another_copy.clear();
    print(another_copy);
    another_copy.emplace_back(30);
    another_copy.emplace(another_copy.begin(), 3);
    print(another_copy);
    return 0;
}