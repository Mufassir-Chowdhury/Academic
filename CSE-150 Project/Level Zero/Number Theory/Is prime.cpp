#include<iostream>

bool prime(int n){
    if(n < 2) return false;
    for(int x=2; x*x <=n; x++)
        if(n%x == 0)
            return false;
    return true;
}

int main(){
    std::cout << prime(3) << std::endl;
    std::cout << prime(22) << std::endl;
    std::cout << prime(37) << std::endl;

    return 0;
}