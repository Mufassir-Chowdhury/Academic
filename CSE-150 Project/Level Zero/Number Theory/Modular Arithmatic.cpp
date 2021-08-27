#include<iostream>

int modAdd(int a, int b, int m){
    return (a%m + b%m) %m;
}
int modSub(int a, int b, int m){
    return (a%m - b%m) %m;    
}
int modMult(int a, int b, int m){
    return (a%m * b%m) %m;
}
int modDiv(int a, int b, int m){
    return (a%m / b%m) %m;    
}
int modPow(int a, int b, int m){
    if (b == 0)
        return 1%m;
    long long u = modPow(a, b/2, m);
    u = modMult(u, u, m);
    if (b%2 == 1)
        u = modMult(u, a, m);
    return u;
}

int main(){
    int a, b, m;
    std::cin >> a >> b >> m;

    std::cout << "(a + b) mod m = " << modAdd(a, b, m) << std::endl;
    std::cout << "(a - b) mod m = " << modSub(a, b, m) << std::endl;
    std::cout << "(a * b) mod m = " << modMult(a, b, m) << std::endl;
    std::cout << "(a / b) mod m = " << modDiv(a, b, m) << std::endl;
    std::cout << "(a ^ b) mod m = " << modPow(a, b, m) << std::endl;

    return 0;
}