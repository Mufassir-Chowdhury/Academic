#include<iostream>
#include<vector>

int main(){
    std::cout << " ---------------------------- " << std::endl;
    std::cout << " \"Insertion Sorting\" program started" << std::endl;
    std::cout << " Written by \"Mufassir Ahmad Chowdhury\"" << std::endl << std::endl;
    int n;
    std::cout << "Enter the size of the array:" << std::endl;
    std::cin >> n;

    std::vector<int> numbers(n);
    
    std::cout << "Enter the values of the array:" << std::endl;
    for(auto &i: numbers)
        std::cin >> i;

    std::cout << "Sorting started..." << std::endl;
    for (size_t i = 1; i < numbers.size(); i++){
        int key = numbers[i];
        int j = i-1;
        while(j >= 0 and numbers[j] > key){
            numbers[j+1] = numbers[j];
            j--;
        }
        numbers[j+1] = key;
    }
    std::cout << "Sorting finished!" << std::endl;
    
    std::cout << std::endl << "Values in the array after sorting is: " << std::endl;
    for(auto i: numbers)
        std::cout << i << " ";
    
    std::cout << std::endl;
    std::cout << " ---------------------------- " << std::endl;

    return 0;
}