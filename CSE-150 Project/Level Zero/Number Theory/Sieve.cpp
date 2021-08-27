#include<iostream>
#include<vector>

int main(){
    std::vector<bool> status(1000001, true);
    std::vector<int> sieve;
    
    status[0] = status[1] = false;
    
    for(int i=2; i< status.size(); i++){
        if(status[i]){
            for(int j=i*i; j<status.size(); j+=i)
                status[j] = false;
            sieve.push_back(i);
        }
    }

    for(auto i: sieve)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << sieve.size() << std::endl;
    return 0;
}