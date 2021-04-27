#include<iostream>
#include<vector>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    
    for(auto &i: numbers)
        std::cin >> i;

    

    return 0;
}