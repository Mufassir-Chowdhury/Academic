#include<bits/stdc++.h>
using namespace std;

int main(){
    string main;
    main = "Hello, World!";
    string copy_of_main(main);
    cout << main << "\n" << copy_of_main << "\n";
    string sub_of_main(main, 7);
    cout << sub_of_main << "\n";

    char c_string[] = "Hello, World!";
    string string_from_c(c_string);
    string sub_of_string(c_string, 5);
    cout << string_from_c << "\n" << sub_of_string << "\n";

    string yummy(5, 'm');
    cout << "Yum" + yummy << "\n";

    string cropped(main.begin(), main.end());
    cout << cropped << "\n";
    
    string another_main = main;
    string another_string_from_c = c_string;
    another_string_from_c += 'c';
    cout << another_main << "\n" << another_string_from_c << "\n";
    
    cout << "length: " << main.length() << "\n" << "size: " << main.size() << "\n";
    cout << "max size:" << main.max_size() << "\n" << "capacity: " << main.capacity() << "\n";
    main.shrink_to_fit();
    cout << "shrinked size: " << main.capacity() << "\n";
    copy_of_main.clear();
    cout << "copy of main: " << copy_of_main << "\n";
    cout << "Is copy of main empty: " << copy_of_main.empty() << "\n";

    cout << main.back() << main.at(12) << main[12] << "\n";
    main.push_back('!');
    cout << main << "\n";
    main.pop_back();
    cout << main << "\n";
    
    sub_of_string.erase(4);
    cout << sub_of_string << "\n";
    
    another_main.replace(7, 6, "String");
    cout << another_main << "\n";
    another_main.append(1, '!');
    cout << another_main << "\n";
    
    another_string_from_c.insert(5, "oooow");
    cout << another_string_from_c << "\n";
    
    another_string_from_c.swap(copy_of_main);
    cout << copy_of_main << " | " << another_string_from_c << "\n";
    
    getline(cin, another_string_from_c);
    const char* c_again = another_string_from_c.c_str();
    cout << c_again << "\n";
    
    cout << another_string_from_c.substr(2, 3) << "\n";
    
    
    return 0;
}