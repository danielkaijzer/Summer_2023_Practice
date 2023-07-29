#include <iostream>
#include <set>
#include <string>
// #include <list>

int main(){
    std::set<std::string> s1 = {"Daniel", "Mary", "Chris", "Lisa"};
    s1.insert("Sam");

    if (s1.find("Sam") == s1.end()){
        std::cout << "Could not find Sam";
    } else {
        std::cout << "Found Sam!";
    } std::cout << std::endl;

    for (auto index = s1.begin(); index != s1.end(); index++){
        std::cout << *index << std::endl;
    }

}