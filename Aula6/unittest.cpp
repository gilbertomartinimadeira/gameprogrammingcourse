#include <iostream>
#include <memory>
#include <sstream>
#include <SFML/Graphics.hpp>


class Person {
    std::string m_name = "N/A";
    bool m_isAlive     = true;
    public:

    Person(std::string name, bool alive): m_name(name),m_isAlive(alive){};

    const std::string getName() 
    {
        return m_name;
    }
    bool isAlive() const
    {
        return m_isAlive;
    }

};
int main(int argc,char * argv[])
{
    std::vector<std::shared_ptr<Person>> myFriends;     

    std::cout << "BEFORE REMOVE_IF: " <<"\n";
    auto friend5 = std::make_shared<Person>("zezek",true);
    auto friend6 = std::make_shared<Person>("gallas",true);
    auto friend7 = std::make_shared<Person>("pedrão",true);
    auto friend8 = std::make_shared<Person>("marcão",true);
    auto friend9 = std::make_shared<Person>("valdeci",false);
    auto friend10 = std::make_shared<Person>("alex",false);
    auto friend11 = std::make_shared<Person>("wilson",false);
    
    myFriends.push_back(friend5);
    myFriends.push_back(friend6);
    myFriends.push_back(friend7);
    myFriends.push_back(friend8);
    myFriends.push_back(friend9);
    myFriends.push_back(friend10);
    myFriends.push_back(friend11);


    for(auto f : myFriends) std::cout << f->getName() <<"\n";        

    std::vector<std::shared_ptr<Person>> myCurrentFriends;

    for(auto f : myFriends) 
    {
        if(f-> isAlive())
        {
            myCurrentFriends.push_back(f);
        }
    }
    myFriends.clear();


    for(auto f : myCurrentFriends)
    {
        myFriends.push_back(f);
    } 

    std::cout << "After removing the dead ones the list is as it goes:" <<"\n";
    for(auto f : myFriends) std::cout << f->getName() <<"\n";            
}