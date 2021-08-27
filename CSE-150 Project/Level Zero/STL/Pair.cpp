#include<iostream>
#include<utility>
using namespace std;

int main(){
    pair<char, int> value('a', 1);
    pair<char, int> copy_of_value(value);
    cout << value.first <<" " << value.second << "\n";
    cout << copy_of_value.first << " " << copy_of_value.second << "\n";
    pair<char, int> new_pair = make_pair('z', 26);
    cout << new_pair.first << " " << new_pair.second << "\n";
    pair<char, int> copy_of_new_pair = new_pair;
    cout << copy_of_new_pair.first << " " << copy_of_new_pair.second << "\n";
    
    copy_of_value.swap(copy_of_new_pair);
    cout << copy_of_value.first << " " << copy_of_value.second << "\n";
    cout << copy_of_new_pair.first << " " << copy_of_new_pair.second << "\n";
    
    swap(copy_of_value, copy_of_new_pair);
    cout << copy_of_value.first << " " << copy_of_value.second << "\n";
    cout << copy_of_new_pair.first << " " << copy_of_new_pair.second << "\n";

    cout << "Is value greater than new_pair: " << (value > new_pair) << "\n";
    cout << get<0>(value) << " " << get<1>(value) << "\n";
    
    return 0;
}