#include <vector>
#include <string>
class Person {
public:
  std::string first;  // first name
  std::string last;   // last name
// copy constructor/assignment declared:
Person(const Person&) = default;
Person& operator=(const Person&) = default;
// NO move constructor/assignment declared
};

int main()
{
    std::vector<Person> coll;
    Person p{"Tina", "Fox"};
    coll.push_back(p); // OK, copies p
    coll.push_back(std::move(p)); // OK, copies p
    return 0;
}