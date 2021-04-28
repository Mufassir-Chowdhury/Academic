#include<iostream>
#include<vector>

std::vector<int> factors(int n){
    std::vector<int> f;
    for(int x=2; x*x <=n; x++){
        while (n%x == 0){
            f.push_back(x);
            n /= x;
        }
    }
    if( n> 1) f.push_back(n);
    return f;
}

int main(){
    std::vector<int> facts1 = factors(10);
    std::vector<int> facts2 = factors(12);

    for(auto i: facts1)
        std::cout << i << " ";
    std::cout << std::endl;

    for(auto i: facts2)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}