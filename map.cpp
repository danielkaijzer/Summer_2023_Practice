#include <iostream>
#include <map>
#include <string>
#include <list>

int main(){
    std::map<std::string, std::list<std::string>> Pokédex;

    std::list<std::string> pikachuAttacks{"thunder shock", "tail whip", "quick attack"};
    std::list<std::string> bulbasaurAttacks{"grass attack", "razor leaf"};

    Pokédex.insert(std::make_pair("Pikachu", pikachuAttacks));
    Pokédex.insert(std::make_pair("Bulbasaur", bulbasaurAttacks));

    for (auto pair : Pokédex){
        std::cout << pair.first << " - ";
        
        for (auto attacks : pair.second)
            std::cout << attacks << ", ";

    std::cout << std::endl;
    }
    
}