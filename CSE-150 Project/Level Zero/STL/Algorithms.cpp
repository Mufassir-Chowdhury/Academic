#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

void print(vector<int> vec){
    for(auto i: vec)
        cout << i << " ";
    cout << endl;
}

bool ascending(int i, int j){
    return i<j;
}

struct Sort{
    bool operator()(int i, int j){
        return i>j;
    }
} descending;


int main(){
    vector<int> values = {23, 45, 25, 235, 325, 52, 52,6 ,7};
    print(values);

    sort(values.begin(), values.end());
    print(values);

    reverse(values.begin(), values.end());
    print(values);

    sort(values.begin(), values.end(), ascending);
    print(values);

    sort(values.begin(), values.end(), descending);
    print(values);

    string str = "abcde";
    while(next_permutation(str.begin(), str.end())){
        cout << str << "\n";
        
    }

    str = "edcba";
    while(prev_permutation(str.begin(), str.end())){
        cout << str << "\n";        
    }

    return 0;
}