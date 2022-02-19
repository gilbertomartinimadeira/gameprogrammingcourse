#include <iostream>
#include <memory>
#include <sstream>
#include <SFML/Graphics.hpp>

int main()
{
    srand(time(NULL));
    for(int i = 0; i < 3; ++i) {
        
        std::cout << rand() <<"\n";
    }
    

}