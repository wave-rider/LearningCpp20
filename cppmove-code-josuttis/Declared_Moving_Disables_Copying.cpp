#include <vector>
#include <string>
class Person {
public:
  std::string first;  // first name
  std::string last;   // last name
// NO copy constructor declared
// move constructor/assignment declared:
Person(Person&&) = default;
Person& operator=(Person&&) = default;
};

int main()
{
    std::vector<Person> coll;
    Person p{"Tina", "Fox"};
    //coll.push_back(p); // ERROR: copying disabled
    coll.push_back(std::move(p)); // OK, moves p
    return 0;
}