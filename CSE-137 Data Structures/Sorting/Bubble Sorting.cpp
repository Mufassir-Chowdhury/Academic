#include<iostream>
#include<vector>

int main(){
    std::cout << " ---------------------------- " << std::endl;
    std::cout << " \"Bubble Sorting\" program started" << std::endl;
    std::cout << " Written by \"Mufassir Ahmad Chowdhury\"" << std::endl << std::endl;
    int n;
    std::cout << "Enter the size of the array:" << std::endl;
    std::cin >> n;

    std::vector<int> numbers(n);
    
    std::cout << "Enter the values of the array:" << std::endl;
    for(auto &i: numbers)
        std::cin >> i;

    std::cout << "Sorting started..." << std::endl;
    
    for(size_t i = 0; i < numbers.size(); i++)
        for(size_t j = i+1; j<numbers.size(); j++)
            if(numbers[j] < numbers[i])
                std::swap(numbers[j], numbers[i]);

    std::cout << "Sorting finished!" << std::endl;
    
    std::cout << std::endl << "Values in the array after sorting is: " << std::endl;
    for(auto i: numbers)
        std::cout << i << " ";
    
    std::cout << std::endl;
    std::cout << " ---------------------------- " << std::endl;

    return 0;
}