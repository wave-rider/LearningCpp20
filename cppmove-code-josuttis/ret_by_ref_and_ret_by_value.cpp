#include <string>
#include <iostream>
#include <vector>
class Person
{

public:
    std::string name;
    std::string getName() &&
    {                           // when we no longer need the value
        std::cout << "getName " << name << " and move \n"; 
        return std::move(name); // we steal and return by value
    }
    const std::string &getName() const &
    {                // in all other cases
        std::cout << "getName " << name << " returns const& \n"; 
        return name; // we give access to the member
    }
};

Person returnPersonByValue()
{
    Person p{"Ben"};
    return p;
}
int main()
{
    Person p{"Ben"};
    std::cout << p.getName() << std::endl;        // 1) fast (returns reference)
    std::cout << returnPersonByValue().getName(); // 2) fast (uses move())
    std::vector<Person> coll;
    //...
    for (const auto &person : coll)
    {
        if (person.getName().empty())
        { // 3) fast (returns reference)
            std::cout << "found empty name\n";
        }
    }
}