#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    queue<int> first;
    queue<int> second({1, 2, 3, 4});
    queue<int> copy_of_second(second);

    cout << first.size() << " " << second.size() << " " << copy_of_second.size() << "\n";

    vector<int> values = {3, 4, 2, 3};
    queue<int, vector<int> > fourth(values);
    cout << fourth.size() << "\n";

    cout << second.back() << " " << second.front() << "\n";
     
    cout << second.size() << " " << second.back() << "\n";
    second.push(3);
    cout << second.size() << " " << second.back() << "\n";
    first.swap(second);
    cout << second.size() << " " << first.size() << "\n";
    first.emplace(2);

    cout << "Is the queue empty: " << second.empty() << "\n";
    second.emplace(3);
    cout << "Is the queue empty: " << second.empty() << "\n";

    while(!first.empty()){
        cout << first.front() << " ";
        first.pop();
    }
    cout << endl;

    cout << first.size() << " " << second.size() << "\n";
    swap(first, second);
    cout << first.size() << " " << second.size() << "\n";

    return 0;
}