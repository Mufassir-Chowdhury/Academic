#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    stack<int> first;
    stack<int> second({1, 2, 3, 4});
    stack<int> copy_of_second(second);    
    
    cout << first.size() << "\n";
    cout << second.size() << "\n";
    cout << copy_of_second.size() << "\n";
    
    cout << "Is the first stack empty: " << first.empty() << "\n";
    
    cout << second.top() << "\n";
    second.top() += 1;
    cout << second.top() << "\n";

    second.push(100);
    cout << second.top() << " " << second.size() << "\n";
    
    first.swap(second);
    cout << "Is the first stack empty now: " << first.empty() << "\n";

    cout << first.size() << " " << first.top() << "\n";
    first.pop();
    cout << first.size() << " " << first.top() << "\n";
    first.emplace(29);

    while(!first.empty()){
        cout << first.top() << " ";
        first.pop();
    }
    cout << "\n";

    vector<int> values = {1, 2, 4, 2, 4};
    stack<int, vector<int> > fourth(values);    

    while(!fourth.empty()){
        cout << fourth.top() << " ";
        fourth.pop();
    }
    cout << "\n";

    return 0;
}